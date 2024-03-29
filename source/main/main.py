import logging

import numpy as np

from source.gui.joystick import main
from source.logs.setup_log import setup_logging
from source.utils.controller import AircraftController

if __name__ == '__main__':
    setup_logging("logs/log.txt")
    initial_position = np.array([0.0, 0.0, 0.0])  # м
    initial_velocity = np.array([0.0, 0.0, 0.0])  # м/c
    initial_orientation = np.array([0.0, 0.0, 0.0])  # град

    controller = AircraftController(initial_position, initial_velocity, initial_orientation)

    angular_velocities = np.array([0, 0, 0])  # угловые скорости [roll_rate, pitch_rate, yaw_rate]
    acceleration = 10  # ускорения [ax, ay, az]
    dt = 50  # Частота подачи данных

    with (open("data/txt/position/x.txt", "w") as f_x,
          open("data/txt/position/y.txt", "w") as f_y,
          open("data/txt/position/z.txt", "w") as f_z,
          open("data/txt/velocity/vx.txt", "w") as f_vx,
          open("data/txt/velocity/vy.txt", "w") as f_vy,
          open("data/txt/velocity/vz.txt", "w") as f_vz,
          open("data/txt/orientation/roll.txt", "w") as f_roll,
          open("data/txt/orientation/pitch.txt", "w") as f_pitch,
          open("data/txt/orientation/yaw.txt", "w") as f_yaw,
          open("data/txt/angular_velocities/w_roll.txt", "w") as f_wroll,
          open("data/txt/angular_velocities/w_pitch.txt", "w") as f_wpitch,
          open("data/txt/angular_velocities/w_yaw.txt", "w") as f_wyaw,
          open("data/txt/a.txt", "w") as f_a,
          open("data/txt/time.txt", "w") as f_time):
        logging.info("Предыдущие логи полетов очищены")

    main(controller, dt)
