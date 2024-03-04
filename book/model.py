import numpy as np

from const import *


class TU154:
    def __init__(self):
        self.V_ = 72.2
        self.sigma_e = 0
        self.sigma_r = 0
        self.sigma_a = 0
        self.sigma_st = -1.26

        # Углы тангажа, рыскания и крена
        self.pitch = 2.94
        self.roll = 0
        self.yaw = 0

        # Составляющие вектора воздушной скорости
        self.Vxg_ = 0
        self.Vyg_ = 0
        self.Vzg_ = 0

        # Абсолютные скорости
        self.Vxg = 67.13
        self.Vyg = -3.13
        self.Vzg = 0

        # Тяга
        self.P = 124500

        # Частота
        self.dt = 50

        # Компоненты скорости ветра
        self.Wxg = -5
        self.Wyg = 0
        self.Wzg = 0

        # Ускорения центра масс самолета в земной системе координат
        self.axg = 0
        self.ayg = 0
        self.azg = 0

        # Координаты центра масс самолета в земной системе координат
        self.x = 0
        self.y = 0
        self.z = 0

        # Угловые скорости в связанной системе координат
        self.wx = 0
        self.wy = 0
        self.wz = 0

        # Угловые ускорения в связанной системе координат
        self.a_wx = 0
        self.a_wy = 0
        self.a_wz = 0

        # Угловое скорости тангажа, рыскания и крена
        self.w_pitch = 0
        self.w_yaw = 0
        self.w_roll = 0

        # Величина J определяется через моменты инерции Ix, Iy, Ixy:
        self.J = Ix * Iy - Ixy**2

    def update(self, sigma_ps, sigma_es, sigma_rs, sigma_as):
        # Изменение силы тяги описывается соотношением
        delta_p = (-self.P + 3538 * (sigma_ps - 41.3))
        self.P += delta_p

        # Для руля высоты
        delta_sigma_e = (4 * (sigma_es - self.sigma_e))
        self.sigma_e += delta_sigma_e
        # if self.sigma_e > 10:
        #     self.sigma_e = 10
        # elif self.sigma_e < -10:
        #     self.sigma_e = -10

        # Для руля направления:
        delta_sigma_r = 4 * (sigma_rs - self.sigma_r)
        self.sigma_r += delta_sigma_r
        # if self.sigma_r > 10:
        #     self.sigma_r = 10
        # elif self.sigma_r < -10:
        #     self.sigma_r = -10

        # Для элеронов:
        delta_sigma_a = 4 * (sigma_as - self.sigma_a)
        self.sigma_a += delta_sigma_a
        # if self.sigma_a > 10:
        #     self.sigma_a = 10
        # elif self.sigma_a < -10:
        #     self.sigma_a = -10

        self.calculation()

    def calculation(self):
        self.Vxg += self.axg / self.dt
        self.Vyg += self.ayg / self.dt
        self.Vzg += self.azg / self.dt

        self.x += self.Vxg / self.dt
        self.y += self.Vyg / self.dt
        self.z += self.Vzg / self.dt

        self.wx += self.a_wx / self.dt
        self.wy += self.a_wy / self.dt
        self.wz += self.a_wz / self.dt

        self.pitch += self.w_pitch / self.dt
        self.roll += self.w_roll / self.dt
        self.yaw += self.w_yaw / self.dt

        # Компоненты скорости ветра wxg , wyg , wzg влияют
        # на составляющие Vxg_ , Vyg_ , Vzg_ вектора воздушной скорости:
        self.Vxg_ = self.Vxg - self.Wxg
        self.Vyg_ = self.Vyg - self.Wyg
        self.Vzg_ = self.Vzg - self.Wzg

        self.V_ = np.sqrt(
            np.square(self.Vxg_) + np.square(self.Vyg_) + np.square(self.Vzg_)
        )

        # Скоростной напор q вычисляется по формуле
        q = p * self.V_**2 / 2

        # Аэродинамические коэффициенты зависят также от угла атаки α
        # и угла скольжения β, которые вычисляются по формулам

        beta = np.rad2deg(
            np.arcsin(
                (
                    self.Vxg_
                    * (
                        np.sin(np.radians(self.yaw))
                        * np.cos(np.radians(self.roll))
                        + np.cos(np.radians(self.yaw))
                        * np.sin(np.radians(self.pitch))
                        * np.sin(np.radians(self.roll))
                    )
                    - self.Vyg_
                    * np.cos(np.radians(self.pitch))
                    * np.sin(np.radians(self.roll))
                    + self.Vzg_
                    * (
                        np.cos(np.radians(self.yaw))
                        * np.cos(np.radians(self.roll))
                        - np.sin(np.radians(self.yaw))
                        * np.sin(np.radians(self.pitch))
                        * np.sin(np.radians(self.roll))
                    )
                )
                / self.V_**2
            )
        )

        alfa = np.rad2deg(
            np.arcsin(
                (
                    -self.Vxg_
                    * (
                        np.sin(np.radians(self.yaw))
                        * np.sin(np.radians(self.roll))
                        - np.cos(np.radians(self.yaw))
                        * np.sin(np.radians(self.pitch))
                        * np.cos(np.radians(self.roll))
                    )
                    - self.Vyg_
                    * np.cos(np.radians(self.pitch))
                    * np.cos(np.radians(self.roll))
                    - self.Vzg_
                    * (
                        np.cos(np.radians(self.yaw))
                        * np.sin(np.radians(self.roll))
                        + np.sin(np.radians(self.yaw))
                        * np.sin(np.radians(self.pitch))
                        * np.cos(np.radians(self.roll))
                    )
                )
                / (self.V_ * np.cos(np.radians(beta)))
            )
        )

        # Коэффициенты cx, cy, cz аэродинамических сил в системе следует брать
        # в связанной системе координат. Они выражаются через коэффициенты
        # cx_, cy_, cz_ в полусвязанной системе соотношениями

        cx_ = 0.21 + 0.004 * alfa + 0.47 * 0.001 * alfa**2
        cy_ = 0.65 + 0.09 * alfa + 0.003 * self.sigma_e
        cz_ = -0.0115 * beta - (0.0034 - 6 * 0.00001 * alfa) * self.sigma_r

        cx = cx_ * np.cos(np.radians(alfa)) - cy_ * np.sin(np.radians(alfa))
        cy = cy_ * np.cos(np.radians(alfa)) + cx_ * np.sin(np.radians(alfa))
        cz = cz_

        # Коэффициенты mx, my, mz аэродинамических моментов определяются следующими
        # выражениями. Для момента относительно оси x (строительная ось самолета):

        mx_beta = -0.0035 - 0.0001 * alfa
        mx_r = -0.0005 + 0.00003 * alfa
        mx_alfa = -0.0004
        mx_x = -0.61 + 0.004 * alfa
        mx_y = -0.3 - 0.012 * alfa
        mx = (
            mx_beta * beta
            + mx_r * self.sigma_r
            + mx_alfa * self.sigma_a
            + (l * 0.5 / self.V_)
            * (np.pi / 180)
            * (mx_x * self.wx + mx_y * self.wy)
        )

        # Для момента относительно оси y:

        my_beta = -0.004 - 0.00005 * alfa
        my_r = -0.00135 + 0.000015 * alfa
        my_alfa = 0
        my_x = 0.015 * alfa
        my_y = -0.21 - 0.005 * alfa
        my = (
            my_beta * beta
            + my_r * self.sigma_r
            + my_alfa * self.sigma_a
            + (l * 0.5 / self.V_)
            * (np.pi / 180)
            * (my_x * self.wx + my_y * self.wy)
        )

        # Для момента относительно оси z:

        mz = (
            0.033
            - 0.017 * alfa
            - 0.013 * self.sigma_e
            + 0.047 * self.sigma_st
            - 1.29 * self.wz / self.V_
        )

        # Аэродинамические моменты:

        Mx = q * s * l * mx
        My = q * s * l * my
        Mz = q * s * b * mz

        # Движение самолета описывается следующей системой
        # дифференциальных уравнений 12-го порядка

        self.axg = (
            (self.P * np.cos(np.radians(sigma)) - q * s * cx)
            * np.cos(np.radians(self.yaw))
            * np.cos(np.radians(self.pitch))
            + (self.P * np.sin(np.radians(sigma)) + q * s * cy)
            * (
                np.sin(np.radians(self.yaw)) * np.sin(np.radians(self.roll))
                - np.cos(np.radians(self.roll))
                * np.cos(np.radians(self.yaw))
                * np.sin(np.radians(self.pitch))
            )
            + q
            * s
            * cz
            * (
                np.sin(np.radians(self.yaw)) * np.cos(np.radians(self.roll))
                + np.cos(np.radians(self.yaw))
                * np.sin(np.radians(self.pitch))
                * np.sin(np.radians(self.pitch))
            )
        ) / m

        self.ayg = (
            (self.P * np.cos(np.radians(sigma)) - q * s * cx)
            * np.sin(np.radians(self.pitch))
            + (self.P * np.sin(np.radians(sigma)) + q * s * cy)
            * np.cos(np.radians(self.pitch))
            * np.cos(np.radians(self.roll))
            - q
            * s
            * cz
            * np.cos(np.radians(self.pitch))
            * np.sin(np.radians(self.roll))
        ) / m - g

        self.azg = (
            (self.P * np.cos(np.radians(sigma)) - q * s * cx)
            * (-np.sin(np.radians(self.yaw)) * np.cos(np.radians(self.pitch)))
            + (self.P * np.sin(np.radians(sigma)) + q * s * cy)
            * (
                np.cos(np.radians(self.yaw)) * np.sin(np.radians(self.roll))
                + np.sin(np.radians(self.yaw))
                * np.sin(np.radians(self.pitch))
                * np.cos(np.radians(self.roll))
            )
            + q
            * s
            * cz
            * (
                np.cos(np.radians(self.yaw)) * np.cos(np.radians(self.roll))
                - np.sin(np.radians(self.yaw))
                * np.sin(np.radians(self.pitch))
                * np.sin(np.radians(self.roll))
            )
        ) / m

        self.w_pitch = self.wz * np.cos(
            np.radians(self.roll)
        ) + self.wy * np.sin(np.radians(self.pitch))
        self.w_yaw = (
            self.wy * np.cos(np.radians(self.roll))
            - self.wz * np.sin(np.radians(self.roll))
        ) / np.cos(np.radians(self.pitch))
        self.w_roll = self.wx - (
            self.wy * np.cos(np.radians(self.roll))
            - self.wz * np.sin(np.radians(self.roll))
        ) / np.tan(np.radians(self.pitch))

        self.a_wz = (
            Ixy * (self.wx**2 - self.wy**2)
            - (Iy - Ix) * self.wx * self.wy
            + Mz
        ) / Iz
        self.a_wy = (
            (Iy - Iz) * Ixy * self.wy * self.wz
            + (Iz - Ix) * Ix * self.wx * self.wz
            + Ix * My
            + Ixy * Mx
            + Ixy * self.wz * (Ix * self.wy - Ixy * self.wx)
        ) / self.J
        self.a_wx = (
            (Iy - Iz) * Iy * self.wy * self.wz
            + (Iz - Ix) * Ixy * self.wx * self.wz
            + Iy * Mx
            + Ixy * My
            + Ixy * self.wz * (Ixy * self.wy - Iy * self.wx)
        ) / self.J
