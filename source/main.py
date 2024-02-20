import numpy as np

from controller import AircraftController

if __name__ == '__main__':
    initial_position = np.array([0.0, 0.0, 0.0])  # м
    initial_velocity = np.array([0.0, 0.0, 0.0])  # м/c
    initial_orientation = np.array([0.0, 0.0, 0.0])  # град

    controller = AircraftController(initial_position, initial_velocity, initial_orientation)

    angular_velocities = np.array([0, 0, 0])  # угловые скорости [roll_rate, pitch_rate, yaw_rate]
    acceleration = 10  # ускорения [ax, ay, az]
    dt = 10  # Частота подачи данных
    for i in range(21):
        print(i)
        if i < 10:
            angular_velocities = np.array([90, 0, 0])
            acceleration = 10
        else:
            angular_velocities = np.array([0, 90, 0])
            acceleration = 0
        controller.control(angular_velocities, acceleration, dt)

        print("Position:", controller.position)
        print("Velocity:", controller.velocity)
        print("Orientation:", controller.orientation)
