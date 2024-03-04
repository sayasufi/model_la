import numpy as np

from const import *


class TU154:
    def __init__(self):
        self.V_ = 0
        self.sigmae = 0
        self.sigmar = 0
        self.sigmaa = 0
        self.sigmast = -1.26

        # Углы тангажа, рыскания и крена
        self.pitch = 0
        self.roll = 0
        self.yaw = 0

        # Составляющие вектора воздушной скорости
        self.Vxg_ = 0
        self.Vyg_ = 0
        self.Vzg_ = 0

        # Абсолютные скорости
        self.Vxg = 0
        self.Vyg = 0
        self.Vzg = 0

        # Тяга
        self.P = 0

        # Частота
        self.dt = 50

        # Компоненты скорости ветра
        self.Wxg = 0
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
        self.J = Ix * Iy - Ixy ** 2

    def update(self, sigmaps, sigmaes, sigmars, sigmaas):
        # Изменение силы тяги описывается соотношением
        delta_P = (-self.P + 3538 * (sigmaps - 41.3)) / self.dt
        self.P += delta_P

        delta_sigmae = (4 * (sigmaes - self.sigmae)) / self.dt
        self.sigmae += delta_sigmae

        # Для руля направления:
        delta_sigmar = 4 * (sigmars - self.sigmar)
        self.sigmar += delta_sigmar

        # Для элеронов:
        delta_sigmaa = 4 * (sigmaas - self.sigmaa)
        self.sigmaa += delta_sigmaa

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

        self.V_ = np.sqrt(np.square(self.Vxg_) + np.square(self.Vyg_) + np.square(self.Vzg_))

        # Скоростной напор q вычисляется по формуле
        q = p * self.V_ ** 2 / 2

        # Аэродинамические коэффициенты зависят также от угла атаки α
        # и угла скольжения β, которые вычисляются по формулам

        beta = np.arcsin((
                                 self.Vxg_ * (np.sin(self.yaw) * np.cos(self.roll) + np.cos(self.yaw) * np.sin(
                             self.pitch) * np.sin(self.roll)) -
                                 self.Vyg_ * np.cos(self.pitch) * np.sin(self.roll) +
                                 self.Vzg_ * (np.cos(self.yaw) * np.cos(self.roll) - np.sin(self.yaw) * np.sin(
                             self.pitch) * np.sin(self.roll))
                         ) / self.V_ ** 2)

        alfa = np.arcsin((
                                 -self.Vxg_ * (np.sin(self.yaw) * np.sin(self.roll) - np.cos(self.yaw) * np.sin(
                             self.pitch) * np.cos(self.roll)) -
                                 self.Vyg_ * np.cos(self.pitch) * np.cos(self.roll) -
                                 self.Vzg_ * (np.cos(self.yaw) * np.sin(self.roll) + np.sin(self.yaw) * np.sin(
                             self.pitch) * np.cos(self.roll))
                         ) / (self.V_ * np.cos(beta)))

        # Коэффициенты cx, cy, cz аэродинамических сил в системе следует брать
        # в связанной системе координат. Они выражаются через коэффициенты
        # cx_, cy_, cz_ в полусвязанной системе соотношениями

        cx_ = 0.21 + 0.004 * alfa + 0.47 * 0.001 * alfa ** 2
        cy_ = 0.65 + 0.09 * alfa + 0.003 * self.sigmae
        cz_ = -0.0115 * beta - (0.0034 - 6 * 0.00001 * alfa) * self.sigmar

        cx = cx_ * np.cos(alfa) - cy_ * np.sin(alfa)
        cy = cy_ * np.cos(alfa) + cx_ * np.sin(alfa)
        cz = cz_

        # Коэффициенты mx, my, mz аэродинамических моментов определяются следующими
        # выражениями. Для момента относительно оси x (строительная ось самолета):

        mxbeta = -0.0035 - 0.0001 * alfa
        mxr = -0.0005 + 0.00003 * alfa
        mxalfa = -0.0004
        mxx = -0.61 + 0.004 * alfa
        mxy = -0.3 - 0.012 * alfa
        mx = mxbeta * beta + mxr * self.sigmar + mxalfa * self.sigmaa + (l * 0.5 / self.V_) * (np.pi / 180) * (
                mxx * self.wx + mxy * self.wy)

        # Для момента относительно оси y:

        mybeta = -0.004 - 0.00005 * alfa
        myr = -0.00135 + 0.000015 * alfa
        myalfa = 0
        myx = 0.015 * alfa
        myy = -0.21 - 0.005 * alfa
        my = mybeta * beta + myr * self.sigmar + myalfa * self.sigmaa + (l * 0.5 / self.V_) * (np.pi / 180) * (
                myx * self.wx + myy * self.wy)

        # Для момента относительно оси z:

        mz = 0.033 - 0.017 * alfa - 0.013 * self.sigmae + 0.047 * self.sigmast - 1.29 * self.wz / self.V_

        # Аэродинамические моменты:

        Mx = q * s * l * mx
        My = q * s * l * my
        Mz = q * s * b * mz

        # Движение самолета описывается следующей системой
        # дифференциальных уравнений 12-го порядка

        self.axg = (
                           (self.P * np.cos(sigma) - q * s * cx) * np.cos(self.yaw) * np.cos(self.pitch) +
                           (self.P * np.sin(sigma) + q * s * cy) * (
                                   np.sin(self.yaw) * np.sin(self.roll) - np.cos(self.roll) * np.cos(self.yaw) * np.sin(
                               self.pitch)) +
                           q * s * cz * (np.sin(self.yaw) * np.cos(self.roll) + np.cos(self.yaw) * np.sin(
                       self.pitch) * np.sin(self.pitch))
                   ) / m

        self.ayg = (
                           (self.P * np.cos(sigma) - q * s * cx) * np.sin(self.pitch) +
                           (self.P * np.sin(sigma) + q * s * cy) * np.cos(self.pitch) * np.cos(self.roll) -
                           q * s * cz * np.cos(self.pitch) * np.sin(self.roll)
                   ) / m - g

        self.azg = (
                           (self.P * np.cos(sigma) - q * s * cx) * (-np.sin(self.yaw) * np.cos(self.pitch)) +
                           (self.P * np.sin(sigma) + q * s * cy) * (
                                   np.cos(self.yaw) * np.sin(self.roll) + np.sin(self.yaw) * np.sin(
                               self.pitch) * np.cos(self.roll)) +
                           q * s * cz * (np.cos(self.yaw) * np.cos(self.roll) - np.sin(self.yaw) * np.sin(
                       self.pitch) * np.sin(self.roll))
                   ) / m

        self.w_pitch = self.wz * np.cos(self.roll) + self.wy * np.sin(self.pitch)
        self.w_yaw = (self.wy * np.cos(self.roll) - self.wz * np.sin(self.roll)) / np.cos(self.pitch)
        self.w_roll = self.wx - (self.wy * np.cos(self.roll) - self.wz * np.sin(self.roll)) / np.tan(self.pitch)

        self.a_wz = (Ixy * (self.wx ** 2 - self.wy ** 2) - (Iy - Ix) * self.wx * self.wy + Mz) / Iz
        self.a_wy = ((Iy - Iz) * Ixy * self.wy * self.wz + (
                Iz - Ix) * Ix * self.wx * self.wz + Ix * My + Ixy * Mx + Ixy * self.wz * (
                             Ix * self.wy - Ixy * self.wx)) / self.J
        self.a_wx = ((Iy - Iz) * Iy * self.wy * self.wz + (
                Iz - Ix) * Ixy * self.wx * self.wz + Iy * Mx + Ixy * My + Ixy * self.wz * (
                             Ixy * self.wy - Iy * self.wx)) / self.J
