import subprocess
import time

# Запускаем первый скрипт
subprocess.Popen(['python', 'main.py'])

# Ждем 2 секунды
time.sleep(3)

# Запускаем второй скрипт
subprocess.Popen(['python', 'graphics.py'])