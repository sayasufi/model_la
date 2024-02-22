import numpy as np
import pandas as pd


def write_csv():
    with (open("data/position/x.txt", "r") as f_x,
          open("data/position/y.txt", "r") as f_y,
          open("data/position/z.txt", "r") as f_z,
          open("data/velocity/vx.txt", "r") as f_vx,
          open("data/velocity/vy.txt", "r") as f_vy,
          open("data/velocity/vz.txt", "r") as f_vz,
          open("data/orientation/roll.txt", "r") as f_roll,
          open("data/orientation/pitch.txt", "r") as f_pitch,
          open("data/orientation/yaw.txt", "r") as f_yaw,
          open("data/angular_velocities/w_roll.txt", "r") as f_wroll,
          open("data/angular_velocities/w_pitch.txt", "r") as f_wpitch,
          open("data/angular_velocities/w_yaw.txt", "r") as f_wyaw,
          open("data/a.txt", "r") as f_a,
          open("data/time.txt", "r") as f_time):
        list_files = [f_time, f_x, f_y, f_z, f_vx, f_vy, f_vz, f_roll, f_pitch, f_yaw, f_wroll, f_wpitch, f_wyaw, f_a]
        names = ["t", "X", "Y", "Z", "V_X", "V_Y",
                 "V_Z",
                 "roll", "pitch", "yaw", "w_roll", "w_pitch", "w_yaw", "a"]

        df = pd.DataFrame()

        for i in range(len(list_files)):
            df[names[i]] = np.loadtxt(list_files[i])

        df.to_csv("data/data.csv", index=False)


if __name__ == "__main__":
    write_csv()
