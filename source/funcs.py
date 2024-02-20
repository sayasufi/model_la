import numpy as np


def calculate_acceleration(acceleration, orientation):
    """Функция для ускорения скорости по трем осям"""
    # Преобразование углов из градусов в радианы
    roll, pitch, yaw = orientation
    yaw = np.radians(yaw)
    roll = np.radians(roll)
    pitch = np.radians(pitch)

    # Расчет скорости в местной географической системе координат
    acceleration_north = acceleration * np.cos(pitch) * np.cos(yaw)
    acceleration_east = acceleration * np.cos(pitch) * np.sin(yaw)
    acceleration_down = acceleration * np.sin(pitch)

    print(acceleration_north, acceleration_east, acceleration_down)
    acceleration_geographical = np.array([acceleration_north, acceleration_east, acceleration_down])

    # # Преобразование скорости из местной системы координат в глобальную
    # acceleration_geographical = np.array([acceleration_north * np.cos(roll) - acceleration_down * np.sin(roll),
    #                                      acceleration_east,
    #                                      acceleration_north * np.sin(roll) + acceleration_down * np.cos(roll)])
    # print(acceleration_geographical)
    return acceleration_geographical
