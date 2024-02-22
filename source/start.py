import logging
import subprocess
import time

from source.logs.setup_log import setup_logging


def start():
    setup_logging("logs/log.txt")
    with open("logs/log.txt", "w"):
        logging.info("Предыдущие логи программы удалены")

    process_map = subprocess.Popen(['python', 'gui/map.py'])
    process_compass = subprocess.Popen(['python', 'gui/compass.py'])
    process1 = subprocess.Popen(['python', 'main/main.py'])

    time.sleep(3)

    process_browser = subprocess.Popen(['python', 'utils/browser_map.py'])
    process_graphs = subprocess.Popen(['python', 'main/graphics.py'])

    process1.wait()
    process_graphs.kill()
    process_compass.kill()
    process_map.kill()
    process_browser.kill()

    # Запускаем третий скрипт
    process5 = subprocess.Popen(['python', 'main/to_csv.py'])
    process5.wait()


if __name__ == '__main__':
    start()
