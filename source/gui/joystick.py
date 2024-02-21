import sys
import threading
import time

import numpy as np
import pygame

from source.data.data_save import save_in_files

flag = 0
ticks = 0
# Инициализация pygame
pygame.init()

# Размеры окна
window_width = 610
window_height = 400

# Цвета
BLACK = (0, 0, 0)
WHITE = (255, 228, 225)
RED = (139, 0, 0)

# Шрифты
FONT = pygame.font.Font(None, 36)
text1 = FONT.render("Ускорение", True, RED)
text2 = FONT.render("Крен, тангаж", True, RED)
text3 = FONT.render("Курс", True, RED)

window = pygame.display.set_mode((window_width, window_height + 70))
pygame.display.set_caption("Джойстик")

# Радиус джойстика
joystick_radius = 50
control_height = 20
control_width = 100
yaw_width = 20
yaw_height = 30


def main_draw(joystick_pos, control_pos, yaw_pos):
    # Очистка экрана
    window.fill(WHITE)
    pygame.draw.line(window, (128, 0, 0), (410, 0), (410, 400))
    pygame.draw.line(window, (128, 0, 0), (0, 200), (610, 200))

    # Рисование джойстика
    pygame.draw.circle(window, BLACK, joystick_pos, joystick_radius)
    pygame.draw.rect(window, BLACK, (
        control_pos[0] - control_width, control_pos[1] - control_height, control_width * 2, control_height * 2))
    pygame.draw.rect(window, BLACK, (
        yaw_pos[0] - yaw_width, yaw_pos[1] - yaw_height, yaw_width * 2, yaw_height * 2))

    window.blit(text1, (30, 0))
    window.blit(text2, (410 - 80, 0))
    window.blit(text3, (10, window_height + 10))

    # Рисование линии
    pygame.draw.rect(window, (105, 105, 105), (200, 0, 10, 400))
    pygame.draw.rect(window, (105, 105, 105), (0, window_height, window_width, 10))


def joystick_update(joystick_pos_in, event):
    joystick_pos_in[0] += event.rel[0]
    joystick_pos_in[1] += event.rel[1]
    # Ограничение перемещения джойстика в пределах окна
    joystick_pos_in[0] = max(210 + joystick_radius, min(window_width - joystick_radius, joystick_pos_in[0]))
    joystick_pos_in[1] = max(joystick_radius, min(window_height - joystick_radius, joystick_pos_in[1]))
    return joystick_pos_in


def control_update(control_update_in, event):
    control_update_in[0] += event.rel[0]
    control_update_in[1] += event.rel[1]
    # Ограничение перемещения джойстика в пределах окна
    control_update_in[0] = max(control_width, min(200 - control_width, control_update_in[0]))
    control_update_in[1] = max(control_height, min(window_height - control_height, control_update_in[1]))
    return control_update_in


def yaw_update(yaw_update_in, event):
    yaw_update_in[0] += event.rel[0]
    yaw_update_in[1] += event.rel[1]
    # Ограничение перемещения джойстика в пределах окна
    yaw_update_in[0] = max(yaw_width, min(window_width - yaw_width, yaw_update_in[0]))
    yaw_update_in[1] = max(yaw_height + 410, min(window_height + 70 - yaw_height, yaw_update_in[1]))
    return yaw_update_in


def main(controller, dt):
    global flag
    global ticks

    # Позиция джойстика
    joystick_pos = [410, window_height // 2]
    control_pos = [100, window_height // 2]
    yaw_pos = [window_width // 2, window_height + 40]

    l_x = [0] * dt
    l_y = [0] * dt
    l_z = [0] * dt
    l_vx = [0] * dt
    l_vy = [0] * dt
    l_vz = [0] * dt
    l_roll = [0] * dt
    l_pitch = [0] * dt
    l_yaw = [0] * dt
    l_time = [0] * dt
    l_a = [0] * dt
    l_wroll = [0] * dt
    l_wpitch = [0] * dt
    l_wyaw = [0] * dt

    k = 0
    # Основной цикл программы
    while True:
        time.sleep(1 / dt)
        # Обработка событий
        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            elif event.type == pygame.MOUSEMOTION:
                if flag == 1:
                    joystick_pos = joystick_update(joystick_pos, event)
                elif flag == 2:
                    control_pos = control_update(control_pos, event)
                elif flag == 3:
                    yaw_pos = yaw_update(yaw_pos, event)
                elif pygame.mouse.get_pressed()[0]:
                    if (joystick_pos[0] - joystick_radius <= pygame.mouse.get_pos()[0] <= joystick_pos[
                        0] + joystick_radius) and (joystick_pos[1] - joystick_radius <= pygame.mouse.get_pos()[1] <=
                                                   joystick_pos[1] + joystick_radius):
                        flag = 1
                    elif (control_pos[0] - control_width <= pygame.mouse.get_pos()[0] <= control_pos[
                        0] + control_width) and (control_pos[1] - control_height <= pygame.mouse.get_pos()[1] <=
                                                 control_pos[1] + control_height):
                        flag = 2
                    elif (yaw_pos[0] - yaw_width <= pygame.mouse.get_pos()[0] <= yaw_pos[
                        0] + yaw_width) and (yaw_pos[1] - yaw_height <= pygame.mouse.get_pos()[1] <=
                                             yaw_pos[1] + yaw_height):
                        flag = 3


            elif event.type == pygame.MOUSEBUTTONUP:
                if flag == 1:
                    joystick_pos = [410, window_height // 2]
                    flag = 0
                elif flag == 3:
                    yaw_pos = [window_width // 2, window_height + 40]
                    flag = 0
                else:
                    flag = 0
        # Отрисовка
        main_draw(joystick_pos, control_pos, yaw_pos)

        # Вывод значений положения джойстика по осям x и y в консоль
        x = (joystick_pos[0] - window_width // 2 - 105) / 5
        y = -(joystick_pos[1] - window_height // 2) / 5
        z = (-control_pos[1] + window_height // 2) / 18
        yaw_cord = (yaw_pos[0] - 305) / 14.25

        # Обновление экрана
        pygame.display.update()
        controller.control(np.array([x, y, yaw_cord]), z, dt)
        l_x[k] = controller.position[0]
        l_y[k] = controller.position[1]
        l_z[k] = controller.position[2]
        l_vx[k] = controller.velocity[0]
        l_vy[k] = controller.velocity[1]
        l_vz[k] = controller.velocity[2]
        l_roll[k] = controller.orientation[0]
        l_pitch[k] = controller.orientation[1]
        l_yaw[k] = controller.orientation[2]
        l_time[k] = ticks / 50
        l_a[k] = z
        l_wroll[k] = x
        l_wpitch[k] = y
        l_wyaw[k] = yaw_cord

        k += 1

        if ticks % dt == 0:
            list_values = [l_x, l_y, l_z, l_vx, l_vy, l_vz, l_roll, l_pitch, l_yaw, l_time, l_wroll, l_wpitch, l_wyaw,
                           l_a]
            thread_file = threading.Thread(target=save_in_files, args=(list_values,), daemon=True)
            thread_file.start()

            l_x = [0] * dt
            l_y = [0] * dt
            l_z = [0] * dt
            l_vx = [0] * dt
            l_vy = [0] * dt
            l_vz = [0] * dt
            l_roll = [0] * dt
            l_pitch = [0] * dt
            l_yaw = [0] * dt
            l_time = [0] * dt
            l_a = [0] * dt
            l_wroll = [0] * dt
            l_wpitch = [0] * dt
            l_wyaw = [0] * dt

            k = 0

        # print("Position:", controller.position)
        # print("Velocity:", controller.velocity)
        # print("Orientation:", controller.orientation)

        ticks += 1
