import subprocess
import time

# Запускаем первый скрипт
process1 = subprocess.Popen(['python', 'main/main.py'])
time.sleep(3)
# Запускаем второй скрипт
process2 = subprocess.Popen(['python', 'main/graphics.py'])

process1.wait()
process2.wait()

# Запускаем третий скрипт
process3 = subprocess.Popen(['python', 'main/to_csv.py'])
process3.wait()
