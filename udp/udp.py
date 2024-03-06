import struct
import time

from unions import Unions


# Определение структуры
class S_UDP_PACK_ODS_DATA:
    def __init__(self):
        self.unions = Unions()
        self.upd = {
            "preface_1": 0xCD,  # Преамбула	0xCDEFFA01
            "preface_2": 0xEF,  # Преамбула
            "preface_3": 0xFA,  # Преамбула
            "preface_4": 0x01,  # Преамбула
            "reciever_addr": 0x0001,  # Адресат пакета 0x0001
            "sender_addr": 0x0002,  # Источник пакета 0x0002
            "id": 0x0003,  # № пакета 0x0003
            "reserv_1": 0x0000,
            "reserv_2": 0x0000,
            "reserv_3": 0x0000,
            "size": 0x0242,  # Длина всего пакета 0x03A2
            "sds1": struct.unpack("H", self.unions.sds1_data)[0],
            "_reserve0": 0x0000,
            "sds2": struct.unpack("H", self.unions.sds2_data)[0],
            "sds3": struct.unpack("H", self.unions.sds3_data)[0],
            "r0": 0x0000,
            "r1": 0x0000,
            "r2": 0x0000,
            "r3": 0x0000,
            "r4": 0x0000,
            "r5": 0x0000,
            "r6": 0x0000,
            "r7": 0x0000,
            "r8": 0x0000,
            "r9": 0x0000,
            "r10": 0x0000,
            "r11": 0x0000,
            "r12": 0x0000,
            "preface_ar_1": 0xA1FA,  # Преамбула канала ARINC-429 №1(Данные ИНС) ВПНП-1М */
            "cnt_p1": 0x00000000,  # Счетчик посылок
            "sds_01_p1": struct.unpack("I", self.unions.sds_01_p1_data)[0],
            "sds_02_p1": struct.unpack("I", self.unions.sds_02_p1_data)[0],
            "sds_03_p1": struct.unpack("I", self.unions.sds_03_p1_data)[0],
            "sds_04_p1": 0x00000000,  # СДС 4
            "sds_05_p1": 0x00000000,  # СДС 5
            "pitch": 0x00000000,  # Угол тангажа
            "roll": 0x00000000,  # Угол крена
            "course_mag": 0x00000000,  # Курс магнитный
            "course_track_mag": 0x00000000,  # Магнитный путевой угол
            "course_true": 0x00000000,  # Истинный курс
            "course_gyro": 0x00000000,  # Гироскопический курс
            "w_x": 0x00000000,  # Угловая скорость тангажа
            "w_y": 0x00000000,  # Угловая скорость крена
            "w_z": 0x00000000,  # Угловая скорость рысканья
            "n_x": 0x00000000,  # Продольное ускорение
            "n_y": 0x00000000,  # Боковое ускорение
            "n_z": 0x00000000,  # Нормальное ускорение
            "L_clx_head": 0x00000000,  # Географические координаты долгота старшая часть
            "L_clx_tail": 0x00000000,  # Географические координаты долгота младшая часть
            "B_clx_head": 0x00000000,  # Географические координаты широта старшая часть
            "B_clx_tail": 0x00000000,  # Географические координаты широта младшая часть
            "H_cmplx": 0x00000000,  # Комплексная высота полета
            "H_otn": 0x00000000,  # Относительная барометрическая высота
            "a_vert": 0x00000000,  # Вертикальное ускорение
            "speed_vert": 0x00000000,  # Вертикальная скорость
            "speed_vert_pot": 0x00000000,  # Потенциальная вертикальная скорость
            "v_north": 0x00000000,  # Путевая скорость N/S
            "v_east": 0x00000000,  # Путевая скорость E/W
            "speed_track": 0x00000000,  # Путевая скорость
            "a_course": 0x00000000,  # Ускорение вдоль траектории полета
            "traj_slope": 0x00000000,  # Угол наклона траектории
            "drift_angle": 0x00000000,  # Угол сноса
            "wind_speed": 0x00000000,  # Скорость ветра
            "wind_angle_mag": 0x00000000,  # Магнитное направление ветра
            "mult_txt": 0x00000000,  # Мультиплексор ТЕХН
            "time_on": 0x00000000,  # Время от включения 005
            "time_nav": 0x00000000,  # Время от начала навигации 006
            "reserv_4": 0x00000000,
            "reserv_5": 0x00000000,
            "reserv_6": 0x00000000,
            "reserv_7": 0x00000000,
            "reserv_8": 0x00000000,
            "reserv_9": 0x00000000,
            "reserv_10": 0x00000000,
            "reserv_11": 0x00000000,
            "p1_end_sig": 0xAF1A,  # Индентификатор окончания пакета №1
        }

        # self.upd_sruct = (
        #     (self.upd["preface_1"] << 48)
        #     | (self.upd["preface_2"] << 32)
        #     | (self.upd["preface_3"] << 16)
        #     | self.upd["preface_4"]
        # )


start = time.time()
# Создание экземпляра структуры
udp_pack = S_UDP_PACK_ODS_DATA()
print(udp_pack.upd["sds1"])

packed_data = struct.pack("H" * 28 + "I" * 48, *udp_pack.upd.values())

print(packed_data)
un = struct.unpack("H" * 28 + "I" * 48, packed_data)
print(un)
print(len(un))
print(time.time() - start)
# # Отправка данных по UDP
# UDP_IP = "127.0.0.1"  # IP адрес получателя
# UDP_PORT = 1234  # Порт получателя
#
# sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# sock.sendto(packed_data, (UDP_IP, UDP_PORT))
# sock.close()
