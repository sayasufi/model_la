import numpy as np


def calculate_new_velocities(acceleration, velocities, orientation, dt):
    """Пересчет скоростей из связанной в географическую СК"""
    # Преобразование углов ориентации в радианы
    roll = np.radians(orientation[0])
    pitch = np.radians(orientation[1])
    yaw = np.radians(orientation[2])

    # Создание матрицы поворота по осям Roll, Pitch, Yaw
    rotation_matrix = np.array([[np.cos(pitch) * np.cos(yaw),
                                 np.cos(pitch) * np.sin(yaw),
                                 -np.sin(pitch)],
                                [np.sin(roll) * np.sin(pitch) * np.cos(yaw) - np.cos(roll) * np.sin(yaw),
                                 np.sin(roll) * np.sin(pitch) * np.sin(yaw) + np.cos(roll) * np.cos(yaw),
                                 np.sin(roll) * np.cos(pitch)],
                                [np.cos(roll) * np.sin(pitch) * np.cos(yaw) + np.sin(roll) * np.sin(yaw),
                                 np.cos(roll) * np.sin(pitch) * np.sin(yaw) - np.sin(roll) * np.cos(yaw),
                                 np.cos(roll) * np.cos(pitch)]])

    local_pryam_vel = np.dot(rotation_matrix, np.array([velocities / dt, 0, 0]))
    print(local_pryam_vel)
    # Создание вектора ускорений в местной системе координат
    local_acceleration = np.dot(rotation_matrix, np.array([acceleration / dt, 0, 0]))

    # Пересчет скоростей по осям в местной системе координат
    new_velocities = local_pryam_vel + local_acceleration
    velocities += acceleration / dt
    return new_velocities, velocities
