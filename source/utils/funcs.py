import numpy as np
from scipy.spatial.transform import Rotation


def scipy_rotate(vector, roll, pitch, yaw):
    """Вращение на вокруг трех осей"""
    m_rot = Rotation.from_euler('xyz', [roll, -pitch, yaw]).as_matrix()
    rot = np.squeeze(np.matmul(vector, m_rot))
    return rot


def rotation_matrix(roll, pitch, yaw):
    """Расчет матрицы поворота из связанной системы координат в местную географическую систему координат"""
    return np.array([
        [
            np.cos(pitch) * np.cos(yaw),
            np.sin(roll) * np.sin(pitch) * np.cos(yaw) - np.cos(roll) * np.sin(yaw),
            np.cos(roll) * np.sin(pitch) * np.cos(yaw) + np.sin(roll) * np.sin(yaw)
        ],
        [
            np.cos(pitch) * np.sin(yaw),
            np.sin(roll) * np.sin(pitch) * np.sin(yaw) + np.cos(roll) * np.cos(yaw),
            np.cos(roll) * np.sin(pitch) * np.sin(yaw) - np.sin(roll) * np.cos(yaw)
        ],
        [
            -np.sin(pitch),
            np.sin(roll) * np.cos(pitch),
            np.cos(roll) * np.cos(pitch)
        ]
    ])


def calculate_new_velocities(acceleration, velocity, orientation, dt):
    """Пересчет скоростей из связанной в географическую СК"""
    # Преобразование углов ориентации в радианы
    roll = np.radians(orientation[0])
    pitch = np.radians(orientation[1])
    yaw = np.radians(orientation[2])

    velocity += acceleration / dt
    if velocity < 0:
        velocity = 0
    if velocity > 300:
        velocity = 300

    # matrix = rotation_matrix(roll, pitch, yaw)
    # local_velocity = np.dot(matrix, np.array([velocity, 0, 0]))

    local_velocity = scipy_rotate(np.array([velocity, 0, 0]), roll, pitch, yaw)
    local_velocity[2] -= 10

    return local_velocity, velocity
