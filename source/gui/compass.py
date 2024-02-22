import math
import socket
import sys

import pygame

# Инициализация pygame
pygame.init()

# Размеры окна
width = 300
height = 300

# Создание окна
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Компас")

# Загрузка картинки компаса
compass_image = pygame.image.load("gui/compass.png")


def draw_compass():
    """Функция для рисования компаса"""
    # with open('data/orientation/yaw.txt', 'rb') as file:
    #     file.seek(0, 2)
    #     file.seek(-2, 1)
    #     while file.read(1).decode() != '\n':
    #         file.seek(-2, 1)
    #     second_last_line = file.readline().decode()
    try:
        second_last_line = float(client_socket.recv(1024).decode())
    except ValueError:
        pygame.quit()
        sys.exit()

    # Очистка экрана
    screen.fill((255, 255, 255))

    # Отображение картинки компаса
    screen.blit(compass_image, (0, 0))

    # Рисование стрелки направления движения
    arrow_length = 90
    arrow_angle = math.radians(float(second_last_line))
    arrow_x = width // 2 + int(arrow_length * math.sin(arrow_angle))
    arrow_y = height // 2 - int(arrow_length * math.cos(arrow_angle))

    # Рисование линии стрелки
    pygame.draw.line(screen, (255, 0, 0), (width // 2, height // 2), (arrow_x, arrow_y), 8)

    # Рисование формы стрелки
    arrow_points = [
        (arrow_x + int(10 * math.sin(arrow_angle + math.pi / 2)),
         arrow_y - int(10 * math.cos(arrow_angle + math.pi / 2))),
        (arrow_x + int(10 * math.sin(arrow_angle - math.pi / 2)),
         arrow_y - int(10 * math.cos(arrow_angle - math.pi / 2))),
        (arrow_x + int(30 * math.sin(arrow_angle)), arrow_y - int(30 * math.cos(arrow_angle)))
    ]
    pygame.draw.polygon(screen, (255, 0, 0), arrow_points)

    # Обновление экрана
    pygame.display.flip()


if __name__ == '__main__':
    # Создаем сокет
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Привязываем сокет к адресу и порту
    server_address = ('localhost', 12345)
    server_socket.bind(server_address)

    # Слушаем входящие соединения
    server_socket.listen(1)

    # Принимаем соединение от клиента
    client_socket, client_address = server_socket.accept()

    running = True
    # Основной цикл программы
    while running:
        # Обработка событий
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        # Рисование компаса
        draw_compass()

    # Завершение программы
    pygame.quit()

