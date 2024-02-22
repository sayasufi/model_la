import logging
import threading
import time

import numpy as np

from source.utils.funcs import calculate_new_velocities, rotation_matrix


class AircraftController:
    def __init__(self, position, velocity, orientation):
        self.position = position  # Начальные координаты летательного аппарата в местной географической системе координат
        self.velocity = velocity  # Начальные скорости летательного аппарата в местной географической системе координат
        self.orientation = orientation  # Начальные углы ориентации летательного аппарата
        self.local_velocity = 0
        self.flag = True

    def control(self, angular_velocities_in, acceleration_in, dt):
        """Пересчет параметров из связанной системы координат в местную географическую систему координат"""

        # rotation_matrix_in = self.calculate_rotation_matrix()
        # np.add(self.orientation, np.dot(rotation_matrix_in, angular_velocities_in) / dt, out=self.orientation)

        np.add(self.orientation, angular_velocities_in / dt, out=self.orientation)
        self.velocity, self.local_velocity = calculate_new_velocities(acceleration_in, self.local_velocity,
                                                                      self.orientation, dt)

        np.add(self.position, self.velocity / dt, out=self.position)
        if self.position[2] < 0 and self.flag and self.velocity[2] + 10 < 0:
            logging.info("Координата по Z не может быть меньше 0")
            self.flag = False
            thread = threading.Thread(target=self.set_flag_true, daemon=True)
            thread.start()

        if self.position[2] <= 0:
            self.position[2] = 0
            self.velocity[2] = 0

    def set_flag_true(self):
        time.sleep(4)
        self.flag = True

    def calculate_rotation_matrix(self):
        """Расчет матрицы поворота из связанной системы координат в местную географическую систему координат"""
        roll = np.radians(self.orientation[0])
        pitch = np.radians(self.orientation[1])
        yaw = np.radians(self.orientation[2])

        return rotation_matrix(roll, pitch, yaw)
