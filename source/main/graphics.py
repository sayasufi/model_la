import matplotlib.animation as animation
import numpy as np
from matplotlib import pyplot as plt

from source.logs.setup_log import setup_logging


def update_plot(frame):
    setup_logging("logs/log.txt")
    with (open("./data/txt/position/x.txt", "r") as f_x,
          open("./data/txt/position/y.txt", "r") as f_y,
          open("./data/txt/position/z.txt", "r") as f_z,
          open("./data/txt/velocity/vx.txt", "r") as f_vx,
          open("./data/txt/velocity/vy.txt", "r") as f_vy,
          open("./data/txt/velocity/vz.txt", "r") as f_vz,
          open("./data/txt/orientation/roll.txt", "r") as f_roll,
          open("./data/txt/orientation/pitch.txt", "r") as f_pitch,
          open("./data/txt/orientation/yaw.txt", "r") as f_yaw,
          open("./data/txt/time.txt", "r") as f_time):
        list_files = [[f_x, f_y, f_z], [f_vx, f_vy, f_vz], [f_roll, f_pitch, f_yaw]]
        list_names = [["Координата Х", "Координата Y", "Координата Z"],
                      ["Скорость по X", "Скорость по Y", "Скорость по Z"], ["Крен", "Тангаж", "Курс"]]
        label_y = ["Расстояние, м", "Скорость, м/c", "Угол, град"]
        time_r = np.loadtxt(f_time)
        n = len(time_r)
        for i in range(3):
            for j in range(3):
                array = np.loadtxt(list_files[i][j])
                axs[i][j].clear()
                axs[i][j].plot(time_r[:n], array[:n])
                axs[i][j].set_title(list_names[i][j])
                axs[i][j].set_xlabel('Время, с')
                axs[i][j].set_ylabel(label_y[i])
                axs[i][j].grid(True)

        plt.subplots_adjust(hspace=0.5, wspace=0.3)
        # if not plt.get_fignums():  # Проверяем, закрыто ли окно с графиками
        #     break


if __name__ == "__main__":
    fig, axs = plt.subplots(3, 3, figsize=(12.5, 10))
    ani = animation.FuncAnimation(fig, update_plot, interval=1000, cache_frame_data=False)
    plt.show()
