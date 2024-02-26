import time

from selenium import webdriver

html_file = 'templates/map.html'

# Запускаем веб-драйвер
driver = webdriver.Chrome()

# Открываем HTML файл в браузере
driver.get(
    "http://localhost:63342/model_la/source/gui/map.html?_ijt=anscn6arjf78dhhjhq6vcv7t2f&_ij_reload=RELOAD_ON_SAVE")

while True:
    # Ждем 1 секунду
    time.sleep(1)

    # Обновляем страницу
    driver.refresh()
