import socket
import subprocess
import sys
import time
import webbrowser

import folium
from environs import Env

from source.utils.convert_coords import local_to_geographic

lat = []
lon = []

env = Env()
env.read_env(".env")
X = float(env("X"))
Y = float(env("Y"))


def update_map():
    global lat
    global lon

    try:
        x, y = client_socket.recv(1024).decode().split(" ")
    except ValueError:
        sys.exit()

    lati, loni = local_to_geographic(float(x) + X, float(y) + Y)

    lat.append(lati)
    lon.append(loni)

    places = [[x[0], x[1]] for x in zip(lat, lon)]

    # Создание карты
    m = folium.Map(places[0], tiles='OpenStreetMap', zoom_start=13)

    # Добавление траектории на карту
    polyline = folium.PolyLine(locations=places, color='blue', weight=3)
    polyline.add_to(m)

    # Сохранение карты в HTML файл
    m.save('gui/map.html')


if __name__ == '__main__':
    # Создаем сокет
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Привязываем сокет к адресу и порту
    server_address = ('localhost', 12346)
    server_socket.bind(server_address)

    # Слушаем входящие соединения
    server_socket.listen(1)

    # Принимаем соединение от клиента
    client_socket, client_address = server_socket.accept()
    while True:
        update_map()
        time.sleep(1)  # Пауза в 1 секунду перед обновлением карты
