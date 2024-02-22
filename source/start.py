import subprocess
import time

from source.logs.setup_log import setup_logging


def start():
    with open("logs/log.txt", "w"):
        pass

    setup_logging("logs/log.txt")

    # Запускаем второй скрипт
    process2 = subprocess.Popen(['python', 'main/graphics.py'])
    time.sleep(1)
    # Запускаем первый скрипт
    process1 = subprocess.Popen(['python', 'main/main.py'])

    process1.wait()
    process2.wait()

    # Запускаем третий скрипт
    process3 = subprocess.Popen(['python', 'main/to_csv.py'])
    process3.wait()


if __name__ == '__main__':
    start()
