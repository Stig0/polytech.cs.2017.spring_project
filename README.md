﻿# polytech.cs.2017.spring_project
**Название проекта: Игра Жизнь**

## Информация о проекте


### Правила
* Место действия этой игры — «вселенная» — это размеченная на клетки поверхность или плоскость — безграничная, ограниченная, или замкнутая (в пределе — бесконечная плоскость).
* Каждая клетка на этой поверхности может находиться в двух состояниях: быть «живой»(заполненной) или быть «мёртвой» (пустой). Клетка имеет восемь соседей, окружающих её.
* Распределение живых клеток в начале игры называется первым поколением. Каждое следующее поколение рассчитывается на основе предыдущего по таким правилам:
1. В пустой (мёртвой) клетке, рядом с которой ровно три живые клетки, зарождается жизнь; 
2. Если у живой клетки есть две или три живые соседки, то эта клетка продолжает жить; в противном случае, если соседей меньше двух или больше трёх, клетка умирает («от одиночества» или «от перенаселённости»)
* Игра прекращается, если
1. На поле не останется ни одной «живой» клетки 
2. Конфигурация на очередном шаге в точности (без сдвигов и поворотов) повторит себя же на одном из более ранних шагов (складывается периодическая конфигурация)
3. При очередном шаге ни одна из клеток не меняет своего состояния (складывается стабильная конфигурация; предыдущее правило, вырожденное до одного шага назад) 

Эти простые правила приводят к огромному разнообразию форм, которые могут возникнуть в игре.

Игрок не принимает прямого участия в игре, а лишь расставляет или генерирует начальную конфигурацию «живых» клеток, которые затем взаимодействуют согласно правилам уже без его участия (он является наблюдателем).
### Интерфейс
![Image alt](https://github.com/Stig0/polytech.cs.2017.spring_project/raw/master/res/play_window.png)
Поле представляет собой набор круглых ячеек  .
Игрок перед началом игры расставляет клетки путем нажатия на пустые . При нажатии на 
пустую клетку она становиться закрашенной ,при повторном –пустой.
* В верхней части игрового окна имеется несколько кнопок управления игрой :
* Кнопка «Старт» - запускает процесс игры .
* Кнопка «Стоп» - останавливает процесс игры. 
* Кнопка «Шаг» - если игровой процесс активен, то останавливает его с заменой . При неактивном игровом процессе выполняет действие 
ровно на один шаг;
* Кнопка «Очистить» - очищает поле от синих клеток ;

В нижней  части игрового окна имеется несколько кнопок автоматического рисования,при нажатии на которые прорисуется определенная фигура .
В нижнем правом углу имеется кнопка выхода в меню.

### Структура проекта
Организация проекта:

Поддиректории| Описание
-------------|-------------------
src/         | программные файлы 
src/tests    | тесты 
doc/         | Документация 
res/         | ресурсы проекта

### Сборка
Для сборки проекта пропишите:
````
make
````
Удалить все собранные файлы:
````
make clean
````
Для сборки тестов:
````
make D_UNITY=../Unity check
````
Для сборки документации:
````
make doxygen
````
Для сборки документации в формате PDF:
````
make pdf
````
Для сборки документации в формате HTML:
````
make html
````

## Авторы
* **Николаев Денис** - den11nik@yandex.ru
* **Пузько Данила** - danilapuzko@mail.ru
## Лицензия
Этот проект лицензирован под MIT License - смотри [LICENSE](LICENSE) файл для подробностей
