#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_native_dialog.h"
#include "functions.h"

const float FPS = 60;
const int SCREEN_W = 1000;
const int SCREEN_H = 600;
const int BOUNCER_SIZE = 32;
int clear(int b[100][100]);
int size_of_matrix = 40;
 float bouncer_x = 0.0;
 float bouncer_y = 0.0;
 int game_mode = 0;
 int planer(int b[100][100]);
 int rellay(int  b[100][100]);
 int Twin_Bees(int b[100][100]);
 int game_window = 0;
 int count_of_clean = 99;
 void knopka(int size_of_matrixint,int *game_mode, int *game_window, int *count_of_clean, int b[100][100], float bouncer_x, float bouncer_y);


int main(int argc, char **argv)

{
	ALLEGRO_DISPLAY_MODE *al_get_display_mode(int index, ALLEGRO_DISPLAY_MODE *mode);
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *image = NULL;
	
	int imageWidth = 0;
	int imageHeight = 0;
	bool redraw = true;
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

	timer = al_create_timer(4.0 / FPS);
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
	image = al_load_bitmap("startstepstopclean2.png");
	image = al_load_bitmap("rules4.png");
	image = al_load_bitmap("randomplanerrellay.png");



	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	al_draw_bitmap(image, 200, 200, 50);
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
	ALLEGRO_FONT *font_pirulen = al_load_font("res/pirulen.ttf", 24, 0);

	al_clear_to_color(al_map_rgb(0, 0, 0));



	al_init_primitives_addon();

	al_flip_display();

	al_start_timer(timer);
	int i, j, k, x, h, y = 1, n = 0, t = 0;
	int a[100][100], b[100][100];
	
	
	
	int kol = 0, kol_max = 300, c1 = 0;
	int life = 0, dead = 0;
	clear(b);
	





	int g = 0;

	al_clear_to_color(al_map_rgb(0, 0, 0));


	while (1)
	{
		count_of_clean++;                         //Процесс очистки экрана,
		if (count_of_clean == 100) {                      //при котором все ненужные элементы удаляются ,
			count_of_clean = 0;                           // а нужные прорисовываются снова



			if (game_window == 0) {                                  //Прорисовка стартового окна

				image = al_load_bitmap("res/fon_menu.jpg"); //Загрузка фона для стартового окна
				al_draw_bitmap(image, 0, 0, 0);             //Прорисовка фона для стартового окна
				if (g == 1)
				{
					image = al_load_bitmap("res/menu_op.jpg"); //Загрузка фона для стартового окна
					al_draw_bitmap(image, 0, 0, 0);           //Прорисовка фона для стартового окна
				}

			}
			if (game_window == 1) {                                      //Начало прорисовки интерфейса игрового процесса
				image = al_load_bitmap("res/play_fon.jpg"); //Загрузка фона
				al_draw_bitmap(image, 0, 0, 0);            //Прорисовка фона
				al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 10, 500, 0, "Random");
				al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 150, 500, 0, "Planer");
				al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 290, 500, 0, "Rellay");
				al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 430, 500, 0, "Twin Bees");
				al_draw_rectangle(5, 500, 130, 545, al_map_rgb(255, 0, 0), 0);
				al_draw_rectangle(145, 500, 260, 545, al_map_rgb(255, 0, 0), 0);
				al_draw_rectangle(285, 500, 395, 545, al_map_rgb(255, 0, 0), 0);
				al_draw_rectangle(425, 500, 580, 545, al_map_rgb(255, 0, 0), 0);
			}
		}
		//Конец процесса прорисовки

		/*Далее программа обрабатывает входяшие команды от пользователя
		Для этого было создано событие EV
		*/
		ALLEGRO_EVENT ev;//Инициализация события
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {   //Подключение таймера
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {  //Случай закрытия пользователем дисплея
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||              //Получение координат мыши от пользователя
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {         //Координаты будут получены если мышь находится в игровом поле
			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;

		}

		/*Далее идет одна из самых важных частей кода-обработка полученных координат мыши .*/

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)   //Координаты обрабатываются при нажатии пользователем на экран
		{
			if (game_window == 1) {//Переменная game_window отвечает за открытие определенного окна ,если game_window=0 - стартовое ,game_window=1 -игровое


				knopka(size_of_matrix, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);
				/*Далее,деяствие,при нажатии на кнопку Random :
				Каждой ячейче матрицы b присваивается рандомное значение 0 или 1
				*/
				if ((bouncer_y > 500 && bouncer_y < 550) && (bouncer_x > 10 && bouncer_x < 120)) {
					srand((unsigned)time(NULL));
					for (j = 1; j < size_of_matrix; j++) {

						for (i = 1; i < size_of_matrix; i++) {

							t = rand() % 2;
							b[i][j] = t;
						}
					}
				}

			}
			/*
			Описание обработки результатов в режиме стартового окна  */
			if (game_window == 0) {
				if ((bouncer_y > 350 && bouncer_y < 390) && (bouncer_x > 410 && bouncer_x < 600)) {//Описание нажатия кнопки Играть
					game_window = 1;
					g = 0;
					al_clear_to_color(al_map_rgb(0, 0, 0));
					count_of_clean = 99;
					clear(b);

				}
				if ((bouncer_y > 450 && bouncer_y < 480) && (bouncer_x > 450 && bouncer_x < 550)) {//Описание нажатия кнопки Выход

					break;
				}
				if ((bouncer_y > 390 && bouncer_y < 430) && (bouncer_x > 420 && bouncer_x < 600)) {//Описание нажатия кнопки Настройки

					al_clear_to_color(al_map_rgb(0, 0, 0));
					if (g == 0) {
						g = 1;

						image = al_load_bitmap("res/menu_op.jpg");
						al_draw_bitmap(image, 0, 0, 0);
					}
					else if (g == 1) {
						g = 0;
						image = al_load_bitmap("res/fon_menu.jpg");
						al_draw_bitmap(image, 0, 0, 0);
					}
				}
			}
			/*
			Действия ,при выборе размера поля (Переменная m отвечает за размер поля  */
			if (g == 1) {
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (bouncer_y > 370 && bouncer_y < 405) && (bouncer_x > 640 && bouncer_x < 850)) {
					size_of_matrix = 10;


				}
				else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (bouncer_y > 405 && bouncer_y < 435) && (bouncer_x > 640 && bouncer_x < 850)) {
					size_of_matrix = 20;

				}
				else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (bouncer_y > 435 && bouncer_y < 465) && (bouncer_x > 640 && bouncer_x < 850)) {
					size_of_matrix = 30;

				}
				else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (bouncer_y > 465 && bouncer_y < 495) && (bouncer_x > 640 && bouncer_x < 850)) {
					size_of_matrix = 40;

				}
			}
		}
		if (game_window == 1) {
			for (y = 1; y < size_of_matrix; y++) {

				for (x = 1; x < size_of_matrix; x++)
				{
					if (b[x][y] == 1) {
						al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(0, 0, 255));
						redraw = true;
					}
					else if (b[x][y] == 0) {
						al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(255, 255, 255));
					}
				}
			}


			if (game_mode == 3)
			{
				game_mode = 0;


			}
			else if (game_mode == 10 || game_mode == 1)
			{
				if (game_mode == 1) game_mode = 0;

				for (y = 1; y < size_of_matrix; y++) {

					for (x = 1; x < size_of_matrix; x++)
					{
						if (b[x][y] == 1) {
							al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(0, 0, 255));
							redraw = true;
						}
						else if (b[x][y] == 0) {
							al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(255, 255, 255));
						}

					}
				}
				for (j = 1; j < size_of_matrix; j++) {
					for (i = 1; i <size_of_matrix; i++) {
						if (b[i - 1][j - 1] == 1) k++;
						if (b[i][j - 1] == 1) k++;
						if (b[i + 1][j - 1] == 1) k++;
						if (b[i - 1][j] == 1) k++;
						if (b[i + 1][j] == 1) k++;
						if (b[i - 1][j + 1] == 1) k++;
						if (b[i][j + 1] == 1) k++;
						if (b[i + 1][j + 1] == 1) k++;
						if (b[i][j] == 1)
						{
							if ((k == 2) || (k == 3))a[i][j] = 1;
							else {
								a[i][j] = 0;
								dead++;
							}
						}
						if (b[i][j] == 0) {
							if ((k == 3)) {
								a[i][j] = 1;
								life++;
							}
							else a[i][j] = 0;
						}
						k = 0;

					}
				}
				int d = 0;
				for (y = 1; y < size_of_matrix; y++) {
					for (x = 1; x < size_of_matrix; x++)
					{
						if (b[x][y] == a[x][y]) d++;

					}
				}
				if (d >size_of_matrix*size_of_matrix - 2 * size_of_matrix) { d = 0; game_mode = 0; }


				for (y = 1; y < size_of_matrix; y++) {
					for (x = 1; x < size_of_matrix; x++)
					{
						b[x][y] = a[x][y];
						redraw = true;
					}
				}

			}

		}

		if (game_window == 0) {
			if (g == 1) {
				al_draw_filled_ellipse(650, 390, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 420, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 450, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 480, 5, 5, al_map_rgb(255, 0, 2));
			}
			if (size_of_matrix == 40 && g == 1) al_draw_filled_ellipse(650, 480, 5, 5, al_map_rgb(0, 255, 2));
			if (size_of_matrix == 30 && g == 1) al_draw_filled_ellipse(650, 450, 5, 5, al_map_rgb(0, 255, 2));
			if (size_of_matrix == 20 && g == 1) al_draw_filled_ellipse(650, 420, 5, 5, al_map_rgb(0, 255, 2));
			if (size_of_matrix == 10 && g == 1) al_draw_filled_ellipse(650, 390, 5, 5, al_map_rgb(0, 255, 2));
			al_flip_display();
		}
		al_flip_display();

	}
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_font(font_goldana);
	al_destroy_font(font_pirulen);

	return 0;
}

