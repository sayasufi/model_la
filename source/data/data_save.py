import matplotlib
from matplotlib import pyplot as plt


save_flag = False


def save_in_files(list_values):
    global save_flag
    plt.ion()
    save_flag = False
    with (open("./data/position/x.txt", "a") as f_x,
          open("./data/position/y.txt", "a") as f_y,
          open("./data/position/z.txt", "a") as f_z,
          open("./data/velocity/vx.txt", "a") as f_vx,
          open("./data/velocity/vy.txt", "a") as f_vy,
          open("./data/velocity/vz.txt", "a") as f_vz,
          open("./data/orientation/roll.txt", "a") as f_roll,
          open("./data/orientation/pitch.txt", "a") as f_pitch,
          open("./data/orientation/yaw.txt", "a") as f_yaw,
          open("./data/angular_velocities/w_roll.txt", "a") as f_wroll,
          open("./data/angular_velocities/w_pitch.txt", "a") as f_wpitch,
          open("./data/angular_velocities/w_yaw.txt", "a") as f_wyaw,
          open("./data/a.txt", "a") as f_a,
          open("./data/time.txt", "a") as f_time):

        list_files = [f_x, f_y, f_z, f_vx, f_vy, f_vz, f_roll, f_pitch, f_yaw, f_time, f_wroll, f_wpitch, f_wyaw, f_a]
        for i in range(len(list_files)):
            for j in list_values[i]:
                list_files[i].write(f"{j}\n")
    # matplotlib.use('agg')
    # plt.style.use("ggplot")
    # fig, axs = plt.subplots(9, 1, figsize=(8, 10))
    # axs = plotting(fig, axs)

    save_flag = True
