import struct
import sys
import time

from arinc import Arinc
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
            "sds4": 0x0000,
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
            "reserv_12": 0x00000000,  # !!!
            # # /******/
            # # /* P2 */
            # # /******/
            "preface_ar_2": 0xA2FA,  # Преамбула канала ARINC-429 №2(Данные СВС) ВПНП-1М
            "cnt_p2": 0x00000000,  # Счетчик посылок
            "sds_01_p2": 0x00000000,  # СДС 1
            "sds_02_p2": 0x00000000,  # СДС 2
            "H_abs": 0x00000000,  # абсолютная барометрическая высота [м]
            "H_qnh": 0x00000000,  # относительная баровысота (коррекция по QNH) [м]
            "H_qfe": 0x00000000,  # относительная баровысота (коррекция по QFE) [м]
            "airspeed_true": 0x00000000,  # истинная (воздушная) скорость [км/ч]
            "airspeed_prib": 0x00000000,  # приборная скорость [км/ч]
            "speed_vert_svs": 0x00000000,  # вертикальная скорость [м/с]
            "M": 0x00000000,  # число Маха полета [ед.М]
            "temp_h": 0x00000000,  # температура наружного воздуха [°С]
            "temp_r": 0x00000000,  # температура торможения [°С]
            "Q": 0x00000000,  # скоростной напор [Па]
            "P_f": 0x00000000,  # Полное давление [мм.рт.ст]
            "P_h_stat": 0x00000000,  # статическое давление воздуха [мм.рт.ст]
            "Td1": 0x00000000,  # температура датчика давления воздуха Д1 [°С]
            "Td2": 0x00000000,  # температура датчика давления воздуха Д2 [°С]
            "reserv_13": 0x00000000,
            "reserv_14": 0x00000000,
            "reserv_15": 0x00000000,
            "reserv_16": 0x00000000,
            "altitude_danger": 0x00000000,  # опасная высота
            "radio_altitude": 0x00000000,  # Высота от Радиовысотомера
            "altitude_trend": 0x00000000,  # Тренд высоты Habs
            "speed_trend": 0x00000000,  # Тренд скорости приборной
            "p2_end_sig": 0xAF2A,
            # # /******/
            # # /* P3 */
            # # /******/
            "preface_ar_3": 0xA3FA,  # Преамбула канала ARINC-429 №3(Данные СНС) ВПНП-1М
            "cnt_p3": 0x00000000,  # Счетчик посылок
            "sds_01_p3": struct.unpack("I", self.unions.sds_01_p3_data)[0],
            "sds_02_p3": 0x00000000,  # СДС 2
            "sds_03_p3": 0x00000000,  # СДС 3
            "hdop": 0x00000000,  # Геометрический фактор HDOP умноженный на 10
            "vdop": 0x00000000,  # Геометрический фактор VDOP умноженный на 10
            "pdop": 0x00000000,  # Геометрический фактор PDOP умноженный на 10
            "vertical_speed_sns": 0x00000000,  # вертикальная скорость
            "speed_track_sns": 0x00000000,  # Путевая скорость
            "v_north_sns": 0x00000000,  # Путевая скорость N/S
            "v_east_sns": 0x00000000,  # Путевая скорость E/W
            "track_angle_sns": 0x00000000,  # путевой угол
            "H_sns": 0x00000000,  # высота СНС [м]
            "L_clx_head_sns": 0x00000000,  # Географические координаты долгота старшая часть
            "L_clx_tail_sns": 0x00000000,  # Географические координаты долгота младшая часть
            "B_clx_head_sns": 0x00000000,  # Географические координаты широта старшая часть
            "B_clx_tail_sns": 0x00000000,  # Географические координаты широта младшая часть
            "time_cur": 0x00000000,  # Текущее время
            "date_cur": 0x00000000,  # Текущая дата
            "reserv_21": 0x00000000,
            "reserv_22": 0x00000000,
            "reserv_23": 0x00000000,
            "reserv_24": 0x00000000,
            "reserv_25": 0x00000000,
            "reserv_26": 0x00000000,
            "reserv_27": 0x00000000,
            "reserv_28": 0x00000000,
            "p3_end_sig": 0xAF3A,  # Идентификатор окончания пакета №3
            "sds1X": 0x0000,
            "sds2X": struct.unpack("H", self.unions.sds2X_data)[0],
            "sds3X": struct.unpack("H", self.unions.sds3X_data)[0],
            "sds4X": 0x0000,
            "pressure": 0x0000,  # Давление(коррекция)
            "flash_page": 0x0000,  # Номер используемой страницы FLASH
            "flash_block": 0x0000,  # Номер используемогог блока FLASH
            "_reserve1": 0x0000,
            "rudder_trim_pos": 0x0000,
            "ailerons_trim_pos": 0x0000,
            "elevator_trim_pos": 0x0000,
            "battery_current": 0x0000,  # Ток аккумулятора
            "battery_voltage": 0x0000,  # Напряжение аккумулятора
            "generator_current": 0x0000,  # Ток генератора
            "generator_voltage": 0x0000,  # Напряжение генератора
            "oil_pressure": 0x0000,  # Давление масла
            "fuel_pressure": 0x0000,  # Давление топлива
            "fuel_consumption": 0x0000,  # Расход топлива
            "oil_temperature": 0x0000,  # Температура масла
            "fuel_rem_l": 0x0000,  # Остаток топлива в левом баке
            "fuel_rem_r": 0x0000,  # Остаток топлива в правом баке
            "engine_torque": 0x0000,  # Значение крутящего момента/шага винта
            "engine_rate": 0x0000,  # Значение оборотов двигателя
            "engine_exhaust_temperature": 0x0000,  # Температура выходящих газов двигателя
            "flaps_position": 0x0000,  # Положение закрылков
            "oil_radiator_position": 0x0000,  # Положение створки маслорадиатора
            "alpha": 0x0000,  # Расчетный угол атаки
            "alpha_min": 0x0000,  # Угол атаки минимально допустимый
            "alpha_max": 0x0000,  # Угол атаки максимально допустимый
            "ny_min": 0x0000,  # Перегрузка минимально допустимая
            "ny_max": 0x0000,  # Перегрузка максимально допустимая
            "speed_min": 0x0000,  # Скорость минимально допустимая
            "speed_max": 0x0000,  # Скорость максимально допустимая
            "fuel_rem": 0x0000,  # Общий остаток топлива
            "rudder_position": 0x0000,  # Положение руля направления
            "ailerons_position": 0x0000,  # Положение элеронов
            "elevator_position": 0x0000,  # Положение руля высоты
            "slide_position": 0x0000,  # Положение шарика скольжения(боковая перегрузка)
            "adjust_course_value": 0x0000,
            "adjust_pitch_value": 0x0000,
            "adjust_roll_value": 0x0000,
            "Nz_filter": 0x0000,
            "Ny_filter": 0x0000,
            "Vy_filter": 0x0000,
            "Alpha_filter": 0x0000,
            "air_temperature": 0x0000,
            "_reserve3": 0x00000000,
            "cnt_ispr": 0x00000000,  # Счетчик исправности
            "crc_pack": 0x00000000,  # Контрольная сумма пакета
        }

        self.arinc = Arinc()

    def update(self, slovar):
        self.upd["pitch"] = struct.unpack(
            "I", self.arinc.get_data("pitch", slovar["PLANE_BANK_DEGREES"])
        )[0]
        self.upd["roll"] = struct.unpack(
            "I", self.arinc.get_data("roll", slovar["PLANE_PITCH_DEGREES"])
        )[0]
        self.upd["course_mag"] = struct.unpack(
            "I",
            self.arinc.get_data(
                "course_mag", slovar["PLANE_HEADING_DEGREES_MAGNETIC"]
            ),
        )[0]
        self.upd["course_track_mag"] = struct.unpack(
            "I",
            self.arinc.get_data(
                "course_track_mag", slovar["-"]
            ),
        )[0]
        self.upd["course_true"] = struct.unpack(
            "I",
            self.arinc.get_data(
                "course_true", slovar["PLANE_HEADING_DEGREES_TRUE"]
            ),
        )[0]
        self.upd["course_gyro"] = struct.unpack(
            "I",
            self.arinc.get_data(
                "course_gyro", slovar["PLANE_HEADING_DEGREES_GYRO"]
            ),
        )[0]
        self.upd["w_x"] = struct.unpack(
            "I",
            self.arinc.get_data(
                "w_x", slovar["ROTATION_VELOCITY_BODY_X"]
            ),
        )[0]
        self.upd["w_y"] = struct.unpack(
            "I",
            self.arinc.get_data(
                "w_y", slovar["ROTATION_VELOCITY_BODY_Z"]
            ),
        )[0]
        self.upd["course_gyro"] = struct.unpack(
            "I",
            self.arinc.get_data(
                "course_gyro", slovar["PLANE_HEADING_DEGREES_GYRO"]
            ),
        )[0]


# Создание экземпляра структуры
udp_pack = S_UDP_PACK_ODS_DATA()

start = time.time()
for i in range(1000):
    udp_pack.update({"PLANE_BANK_DEGREES": i % 30})
    packed_data = struct.pack(
        "H" * 27 + "I" * 105 + "H" * 46 + "I" * 3, *udp_pack.upd.values()
    )
print(time.time() - start)
print(packed_data)
print(sys.getsizeof(packed_data) - sys.getsizeof(b""))
# un = struct.unpack("H" * 28 + "I" * 104 + "H" * 46 + "I" * 3, packed_data)
# print(un)
# print(len(un))

# # Отправка данных по UDP
# UDP_IP = "127.0.0.1"  # IP адрес получателя
# UDP_PORT = 1234  # Порт получателя
#
# sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# sock.sendto(packed_data, (UDP_IP, UDP_PORT))
# sock.close()
