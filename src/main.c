/** @file main.c
*  @brief Главная функция проекта
*
*  Главная функция проекта.В данной функции подключается библиотека Allegro5 и различные ее пакеты.Функция отвечает за работу дисплея .
*  Работа программы строится на бесконечном цикле ,в процессе которого прорисовываютя различные элементы дисплея.
*@author Nikolaev Denis - den11nik@yandex.ru \n
*@author Puzko Danila - danilapuzko@mail.ru*/
/** \fn int main(int argc, char **argv)
Работа программы строится на бесконечном цикле ,в процессе которого прорисовываютя различные элементы дисплея.
##Игровой цикл можно разделить на 3 части:
###Первая часть:
** *Эта часть представляет собой набор команд для отрисовки игрового поля (В ней загружается игровой фон,кнопки )*
###Вторая часть:
** *Эта часть отвечает за подключение события взаимодействия с пользователем,в данном случае ввод пользователем данных при помощи мыши .*
** *Если игровая мышь находится в игровом поле и на ней нажимается кнопка,программа получает координаты и отправляет их в функцию knopka*
###Третья часть:
** *Эта часть отвечает за отрисовку игрового поля в зависимости от состояния матрицы b*
*
*/

#include "lib.h"
#include "main.h"

int main(int argc, char **argv)
{//С 38 по 119 строчку инициализация различных механизмов библиотеки
	ALLEGRO_DISPLAY_MODE *al_get_display_mode(int index, ALLEGRO_DISPLAY_MODE *mode);
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *image1 = NULL;
	ALLEGRO_BITMAP *image3 = NULL;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	if (!al_install_mouse()) {
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}
	timer = al_create_timer(0.5 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}
	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	if (!bouncer) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	image1 = al_load_bitmap("res/fon_menu.jpg");
	image3 = al_load_bitmap("res/play_fon.jpg");
	if (!image1) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	al_draw_bitmap(image1, 0, 0, 0);
	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 0, 255));
	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	al_install_keyboard();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon
	ALLEGRO_FONT *font_goldana = al_load_font("res/Goldana.ttf", 45, 0);
	ALLEGRO_FONT *font_goldana1 = al_load_font("res/Goldana.ttf", 35, 0);
	al_init_primitives_addon();
	al_flip_display();
	al_start_timer(timer);
	int x = 0, y = 0;//Переменные для циклов FOR
	int number_of_neighbors = 0;//Счетчик количества соседей у каждой живой клетки
	al_clear_to_color(al_map_rgb(0, 0, 0));
	clear(buffer_matrix);
	while (Game_on == 1)
	{
		count_of_clean++; //Процесс очистки экрана,
		if (count_of_clean == 100 || count_of_clean == 80) {
			al_clear_to_color(al_map_rgb(0, 0, 0));//при котором все ненужные элементы удаляются ,
			count_of_clean = 0; // а нужные прорисовываются снова
			if (game_window == 0) { //Прорисовка стартового окна

				al_draw_bitmap(image1, 0, 0, 0); //Прорисовка фона для стартового окна
			}
			else if (game_window == 1) { //Начало прорисовки интерфейса игрового процесса
				al_draw_bitmap(image3, 0, 0, 0); //Прорисовка фона
				al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 10, 500, 0, "Random");
				al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 150, 500, 0, "Planer");
				if (size_of_matrix > 20) {
					al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 290, 500, 0, "Rellay");
					al_draw_rectangle(285, 500, 395, 545, al_map_rgb(255, 0, 0), 0);
				}
				if (size_of_matrix > 30) {
					al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 430, 500, 0, "Twin Bees");
					al_draw_rectangle(425, 500, 580, 545, al_map_rgb(255, 0, 0), 0);
				}
				al_draw_rectangle(5, 500, 130, 545, al_map_rgb(255, 0, 0), 0);
				al_draw_rectangle(145, 500, 260, 545, al_map_rgb(255, 0, 0), 0);
				for (y = 1; y < size_of_matrix; y++) {
					for (x = 1; x < size_of_matrix; x++)
					{
						if (buffer_matrix[x][y] == 1) {
							al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(0, 0, 255));
						}
						else if (buffer_matrix[x][y] == 0) {
							al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(255, 255, 255));
						}
						else {}
					}
				}
			}
			else {}
		}
		//Конец процесса прорисовки
		/*Далее программа обрабатывает входяшие команды от пользователя
		Для этого было создано событие EV
		*/
		ALLEGRO_EVENT ev;//Инициализация события
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { //Случай закрытия пользователем дисплея
			break;
		}

		/*Далее идет одна из самых важных частей кода-обработка полученных координат мыши .*/
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) //Координаты обрабатываются при нажатии пользователем на экран
		{
			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;
			count_of_clean = 79;
			knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, buffer_matrix, bouncer_x, bouncer_y);
			al_flush_event_queue(event_queue);
			/*
			Прорисовка меню настроек*/
			if (game_window == 0) {
				if (size_settings == 1) {
					size_matrix(&size_of_matrix, bouncer_x, bouncer_y);
				}
				if ((bouncer_y > 390 && bouncer_y < 430) && (bouncer_x > 420 && bouncer_x < 600)) {//Описание нажатия кнопки Настройки
					if (size_settings == 0) {
						size_settings = 1;
					}
					else if (size_settings == 1) {
						size_settings = 0;
					}
					else {}
				}

			}
		}
		else {}
		if (game_window == 1) {
			//Остановка игрового цикла
			if (game_mode == 3)
			{
				game_mode = 0;
			}
			else if (game_mode == 10 || game_mode == 1)
			{
				if (game_mode == 1) { game_mode = 0; }
				if (count_of_clean == 79) {
					main_algorithm(buffer_matrix, main_matrix, number_of_neighbors, size_of_matrix, &game_mode);
					al_flush_event_queue(event_queue);
					al_flip_display();
				}
			}
			else {}
		}
		//Следующая часть кода отвечает за красные и зеленые ячейки напротив размера поля
		else if (game_window == 0) {
			if (size_settings == 1) {
				al_draw_filled_ellipse(650, 390, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 420, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 450, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 480, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 510, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_text(font_goldana1, al_map_rgb(255, 255, 255), 640, 330, 0, "Size of field");
				al_draw_text(font_goldana1, al_map_rgb(255, 255, 255), 680, 495, 0, "100*100");
				al_draw_text(font_goldana1, al_map_rgb(255, 255, 255), 680, 465, 0, "40*40");
				al_draw_text(font_goldana1, al_map_rgb(255, 255, 255), 680, 435, 0, "30*30");
				al_draw_text(font_goldana1, al_map_rgb(255, 255, 255), 680, 405, 0, "20*20");
				al_draw_text(font_goldana1, al_map_rgb(255, 255, 255), 680, 375, 0, "10*10");
				if (size_of_matrix == 41) { al_draw_filled_ellipse(650, 480, 5, 5, al_map_rgb(0, 255, 2)); }
				else if (size_of_matrix == 31) { al_draw_filled_ellipse(650, 450, 5, 5, al_map_rgb(0, 255, 2)); }
				else if (size_of_matrix == 21) { al_draw_filled_ellipse(650, 420, 5, 5, al_map_rgb(0, 255, 2)); }
				else if (size_of_matrix == 11) { al_draw_filled_ellipse(650, 390, 5, 5, al_map_rgb(0, 255, 2)); }
				else if (size_of_matrix == 99) { al_draw_filled_ellipse(650, 510, 5, 5, al_map_rgb(0, 255, 2)); }
				else {}
				al_flip_display();
			}
			else {}
		}
		else {}
		al_flip_display();
	}
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_font(font_goldana);
	al_destroy_font(font_goldana1);
	return 0;
}
