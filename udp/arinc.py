import struct


def parity(value):
    # Инициализация переменной для хранения бита четности
    parity = 0
    # Цикл для обработки каждого бита числа
    for x in range(31):
        # Проверка последнего бита числа
        parity += value & 0x0001
        # Сдвиг числа вправо на 1 бит
        value = value >> 1
    # Проверка бита четности
    if parity & 0x1:
        return 1
    else:
        return 0


class Arinc:
    def __init__(self):

        self.id = {
            "pitch": 212,
            "roll": 213,
            "course_mag": 208,
            "course_track_mag": 207,
            "course_true": 204,
            "course_gyro": 220,
            "w_x": 222,
            "w_y": 223,
            "w_z": 216,
            "n_x": 217,
            "n_y": 218,
            "n_z": 219,
            "H_cmplx": 242,
            "H_otn": 243,
            "a_vert": 244,
            "speed_vert": 245,
            "speed_vert_pot": 240,
            "v_north": 251,
            "v_east": 252,
            "speed_track": 202,
            "a_course": 211,
            "traj_slope": 210,
            "drift_angle": 209,
            "wind_speed": 205,
            "H_abs": 242,
            "H_qnh": 242,
            "H_qfe": 242,
            "airspeed_true": 205,
            "airspeed_prib": 205,
            "speed_vert_svs": 240,
        }

        self.data = {
            "ucLabel": 0,  # Идентификатор типа данных
            "ucSdi": 0,  # Идентификаторы источника/назначения
            "ulData": 0,  # Основные данные
            "ucStatus": 3,  # Матрица состояния
            "ucParity": 0,  # Бит чётности
        }

    def get_data(self, name, value):
        self.data["ucLabel"] = self.id[name]
        self.data["ulData"] = value
        self.data["ucParity"] = parity(value)

        data_struct = (
            (self.data["ucLabel"] << 24)
            | (self.data["ucSdi"] << 22)
            | (self.data["ulData"] << 3)
            | (self.data["ucStatus"] << 1)
            | self.data["ucParity"]
        )

        string = struct.pack(">I", data_struct)
        return string


# arinc = Arinc()
# a = arinc.get_data("roll", 10)
# print(a)
# b = struct.unpack(">I", a)
# print(b)
# print(struct.pack(">I", b[0]))
