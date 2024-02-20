import numpy as np

from source.funcs import calculate_acceleration


class AircraftController():
    def __init__(self, position, velocity, orientation):
        self.position = position  # Начальные координаты летательного аппарата в местной географической системе координат
        self.velocity = velocity  # Начальные скорости летательного аппарата в местной географической системе координат
        self.orientation = orientation  # Начальные углы ориентации летательного аппарата

    def control(self, angular_velocities_in, acceleration_in, dt):
        """Пересчет параметров из связанной системы координат в местную географическую систему координат"""
        rotation_matrix = self.calculate_rotation_matrix()
        accelerations = calculate_acceleration(acceleration_in, self.orientation)
        np.add(self.velocity, np.dot(rotation_matrix, accelerations)/dt, out=self.velocity)
        self.position += self.velocity/dt
        np.add(self.orientation, np.dot(rotation_matrix, angular_velocities_in) / dt, out=self.orientation)
        # self.orientation += angular_velocities_in/dt

    def calculate_rotation_matrix(self):
        """Расчет матрицы поворота из связанной системы координат в местную географическую систему координат"""
        roll = np.radians(self.orientation[0])
        pitch = np.radians(self.orientation[1])
        yaw = np.radians(self.orientation[2])

        rotation_matrix = np.array([
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

        return rotation_matrix
