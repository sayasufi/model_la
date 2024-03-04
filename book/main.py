import numpy as np

from const import *

V_ = 50
pitch = 0
yaw = 0
roll = 0

# Пусть изменение силы тяги описывается соотношением

delta_P = -P + 3538 * (sigmaps - 41.3)

# Для руля высоты:

delta_sigmae = 4 * (sigmaes - sigmae)

# Для руля направления:

delta_sigmar = 4 * (sigmars - sigmar)

# Для элеронов:

delta_sigmaa = 4 * (sigmaas - sigmaa)

# Скоростной напор q вычисляется по формуле

q = p * V_ ** 2 / 2

# Величина J определяется через моменты инерции Ix, Iy, Ixy:

J = Ix * Iy - Ixy ** 2


# Компоненты скорости ветра wxg , wyg , wzg влияют
# на составляющие Vxg_ , Vyg_ , Vzg_ вектора воздушной скорости:

Vxg_ = Vxg - wxg
Vyg_ = Vyg - wyg
Vzg_ = Vzg - wzg

# Аэродинамические коэффициенты зависят также от угла атаки α
# и угла скольжения β, которые вычисляются по формулам

beta = np.arcsin((
                         Vxg_ * (np.sin(yaw) * np.cos(roll) + np.cos(yaw) * np.sin(pitch) * np.sin(roll)) -
                         Vyg_ * np.cos(pitch) * np.sin(roll) +
                         Vzg_ * (np.cos(yaw) * np.cos(roll) - np.sin(yaw) * np.sin(pitch) * np.sin(roll))
                 ) / V_ ** 2)

alfa = np.arcsin((
                         -Vxg_ * (np.sin(yaw) * np.sin(roll) - np.cos(yaw) * np.sin(pitch) * np.cos(roll)) -
                         Vyg_ * np.cos(pitch) * np.cos(roll) -
                         Vzg_ * (np.cos(yaw) * np.sin(roll) + np.sin(yaw) * np.sin(pitch) * np.cos(roll))
                 ) / (V_ * np.cos(beta)))

# Коэффициенты cx, cy, cz аэродинамических сил в системе следует брать
# в связанной системе координат. Они выражаются через коэффициенты
# cx_, cy_, cz_ в полусвязанной системе соотношениями

cx_ = 0.21 + 0.004 * alfa + 0.47 * 0.001 * alfa ** 2
cy_ = 0.65 + 0.09 * alfa + 0.003 * sigmae
cz_ = -0.0115 * beta - (0.0034 - 6 * 0.00001 * alfa) * sigmar

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

mx = mxbeta * beta + mxr * sigmar + mxalfa * sigmaa + (l * 0.5 / V_) * (np.pi / 180) * (mxx * wx + mxy * wy)

# Для момента относительно оси y:

mybeta = -0.004 - 0.00005 * alfa
myr = -0.00135 + 0.000015 * alfa
myalfa = 0
myx = 0.015 * alfa
myy = -0.21 - 0.005 * alfa

my = mybeta * beta + myr * sigmar + myalfa * sigmaa + (l * 0.5 / V_) * (np.pi / 180) * (myx * wx + myy * wy)

# Для момента относительно оси z:

mz = 0.033 - 0.017 * alfa - 0.013 * sigmae + 0.047 * sigmast - 1.29 * wz / V_

# Аэродинамические моменты:

Mx = q * s * l * mx
My = q * s * l * my
Mz = q * s * b * mz

# Движение самолета описывается следующей системой
# дифференциальных уравнений 12-го порядка

axg = (
              (P * np.cos(sigma) - q * s * cx) * np.cos(yaw) * np.cos(pitch) +
              (P * np.sin(sigma) + q * s * cy) * (
                      np.sin(yaw) * np.sin(roll) - np.cos(roll) * np.cos(yaw) * np.sin(pitch)) +
              q * s * cz * (np.sin(yaw) * np.cos(roll) + np.cos(yaw) * np.sin(pitch) * np.sin(pitch))
      ) / m

ayg = (
              (P * np.cos(sigma) - q * s * cx) * np.sin(pitch) +
              (P * np.sin(sigma) + q * s * cy) * np.cos(pitch) * np.cos(roll) -
              q * s * cz * np.cos(pitch) * np.sin(roll)
      ) / m - g

azg = (
              (P * np.cos(sigma) - q * s * cx) * (-np.sin(yaw) * np.cos(pitch)) +
              (P * np.sin(sigma) + q * s * cy) * (
                      np.cos(yaw) * np.sin(roll) + np.sin(yaw) * np.sin(pitch) * np.cos(roll)) +
              q * s * cz * (np.cos(yaw) * np.cos(roll) - np.sin(yaw) * np.sin(pitch) * np.sin(roll))
      ) / m

w_pitch = wz * np.cos(roll) + wy * np.sin(pitch)
w_yaw = (wy * np.cos(roll) - wz * np.sin(roll)) / np.cos(pitch)
w_roll = wx - (wy * np.cos(roll) - wz * np.sin(roll)) / np.tan(pitch)

a_wz = (Ixy * (wx ** 2 - wy ** 2) - (Iy - Ix) * wx * wy + Mz) / Iz
a_wy = ((Iy - Iz) * Ixy * wy * wz + (Iz - Ix) * Ix * wx * wz + Ix * My + Ixy * Mx + Ixy * wz * (Ix * wy - Ixy * wx)) / J
a_wx = ((Iy - Iz) * Iy * wy * wz + (Iz - Ix) * Ixy * wx * wz + Iy * Mx + Ixy * My + Ixy * wz * (Ixy * wy - Iy * wx)) / J
