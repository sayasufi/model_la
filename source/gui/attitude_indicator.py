import math
import socket
import sys

import pygame

# Инициализация pygame
pygame.init()

# Размеры окна
width = 300
height = 300
radius = width // 2

x = width // 2
y = height // 2

# Создание окна
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Авиагоризонт")


def attitude_indicator():
    """Авиагоризонт"""

    try:
        roll, pitch = client_socket.recv(1024).decode().split(" ")
        roll = -float(roll)
        pitch = float(pitch)
    except ValueError:
        pygame.quit()
        sys.exit()

    # Очистка экрана
    screen.fill((0, 0, 0))
    pygame.draw.circle(screen, (255, 255, 255), (x, y), radius)
    pygame.draw.line(screen, (139, 0, 0), (x, 0), (x, height), 2)
    pygame.draw.line(screen, (139, 0, 0), (0, y), (width, y), 2)

    if math.cos(math.radians(pitch)) > 0:
        delta = 1
    else:
        delta = -1

    start_x = x - radius * 4 * math.cos(math.radians(roll))
    start_y = y - radius * 4 * math.sin(math.radians(roll)) - radius * math.sin(math.radians(pitch)) * delta
    end_x = x + radius * 4 * math.cos(math.radians(roll))
    end_y = y + radius * 4 * math.sin(math.radians(roll)) - radius * math.sin(math.radians(pitch)) * delta

    pygame.draw.line(screen, (0, 170, 0), (start_x, start_y), (end_x, end_y), 8)

    pygame.display.flip()


if __name__ == '__main__':
    # Создаем сокет
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Привязываем сокет к адресу и порту
    server_address = ('localhost', 12347)
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
        attitude_indicator()

    # Завершение программы
    pygame.quit()
