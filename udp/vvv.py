import ctypes
import socket


# Определение структуры
class S_UDP_PACK_ODS_DATA(ctypes.Structure):
    _fields_ = [
        ("preface_1", ctypes.c_uint16),
        ("preface_2", ctypes.c_uint16),
        ("preface_3", ctypes.c_uint16),
        ("preface_4", ctypes.c_uint16),
        ("reciever_addr", ctypes.c_uint16),
        ("sender_addr", ctypes.c_uint16),
        ("id", ctypes.c_uint16),
        ("reserv_1", ctypes.c_uint16),
        ("reserv_2", ctypes.c_uint16),
        ("reserv_3", ctypes.c_uint16),
        ("size", ctypes.c_uint16),
        ("sds1", ctypes.c_uint16),
    ]


# Создание сокета для прослушивания подключений
UDP_IP = "127.0.0.1"  # IP адрес сервера
UDP_PORT = 1234  # Порт сервера

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print("Сервер запущен и ожидает подключений...")

while True:
    # Получение данных
    data, addr = sock.recvfrom(ctypes.sizeof(S_UDP_PACK_ODS_DATA))

    # Декодирование битовой строки
    decoded_string = int.from_bytes(data, byteorder="little")

    # Представление в виде единиц и нулей
    binary_representation = bin(decoded_string)[2:].zfill(16)

    print(binary_representation)
    print(data)

    # # Преобразование бинарных данных в структуру
    # udp_pack = S_UDP_PACK_ODS_DATA()
    # ctypes.memmove(ctypes.addressof(udp_pack), data, ctypes.sizeof(udp_pack))
    #
    # # Вывод значений полей
    # print("Получены данные от адреса", addr)
    # print("preface_1:", hex(udp_pack.preface_1))
    # print("preface_2:", hex(udp_pack.preface_2))
    # print("preface_3:", hex(udp_pack.preface_3))
    # print("preface_4:", hex(udp_pack.preface_4))
    # print("reciever_addr:", udp_pack.reciever_addr)
    # print("sender_addr:", udp_pack.sender_addr)
    # print("id:", udp_pack.id)
    # print("reserv_1:", udp_pack.reserv_1)
    # print("reserv_2:", udp_pack.reserv_2)
    # print("reserv_3:", udp_pack.reserv_3)
    # print("size:", udp_pack.size)
    # print("sds1:", bin(udp_pack.sds1))
    # print()

sock.close()
