
/** @file main.c
 *  @brief ������� ������� �������
 *
 *  ������� ������� �������.� ������ ������� ������������ ���������� Allegro5 � ��������� �� ������.������� �������� �� ������ ������� .
 *  ������ ��������� �������� �� ����������� ����� ,� �������� �������� �������������� ��������� �������� �������.
    *@author Nikolaev Denis - den11nik@yandex.ru \n
    *@author Puzko Danila - danilapuzko@mail.ru*/
/** \fn int main(int argc, char **argv)
������ ��������� �������� �� ����������� ����� ,� �������� �������� �������������� ��������� �������� �������.
##������� ���� ����� ��������� �� 3 �����:
###������ �����:
** *��� ����� ������������ ����� ����� ������ ��� ��������� �������� ���� (� ��� ����������� ������� ���,������ )*
###������ �����:
** *��� ����� �������� �� ����������� ������� �������������� � �������������,� ������ ������ ���� ������������� ������ ��� ������ ���� .*
** *���� ������� ���� ��������� � ������� ���� � �� ��� ���������� ������,��������� �������� ���������� � ���������� �� � ������� knopka*
###������ �����:
** *��� ����� �������� �� ��������� �������� ���� � ����������� �� ��������� ������� b*
 *

 */


#include "lib.h"
#include "main.h"


int main(int argc, char **argv)

{//� 38 �� 119 ������� ������������� ��������� ���������� ����������
	ALLEGRO_DISPLAY_MODE *al_get_display_mode(int index, ALLEGRO_DISPLAY_MODE *mode);
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *image = NULL;

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

	timer = al_create_timer(2.0 / FPS);
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


	image = al_load_bitmap("src/res/fon_menu.jpg");
	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	al_draw_bitmap(image, 0, 0, 0);
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

	ALLEGRO_FONT *font_goldana = al_load_font("src/res/Goldana.ttf", 45, 0);

	al_init_primitives_addon();
	al_flip_display();
	al_start_timer(timer);

	int x = 0, y = 0;//���������� ��� ������ FOR
	int a[100][100], b[100][100];//��� �������� ������� ���� (�� ���������� ������� � ����� ���������� ������� )
	int number_of_neighbors = 0;//������� ���������� ������� � ������ ����� ������
	int size_settings = 0; //����� ���� ������ ������� �������(��� size_settings=0 ���� �������,��� size_settings=1 ���� �������
	int Game_on = 1;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	clear(b);

	while (Game_on == 1)
	{
		count_of_clean++; //������� ������� ������,
		if (count_of_clean == 100) { //��� ������� ��� �������� �������� ��������� ,
			count_of_clean = 0; // � ������ ��������������� �����
			if (game_window == 0) { //���������� ���������� ����

				image = al_load_bitmap("src/res/fon_menu.jpg"); //�������� ���� ��� ���������� ����
				al_draw_bitmap(image, 0, 0, 0); //���������� ���� ��� ���������� ����
				if (size_settings == 1)
				{
					image = al_load_bitmap("src/res/menu_op.jpg"); //�������� ���� ��� ���������� ����
					al_draw_bitmap(image, 0, 0, 0); //���������� ���� ��� ���������� ����
				}

			}

			if (game_window == 1) { //������ ���������� ���������� �������� ��������
				image = al_load_bitmap("src/res/play_fon.jpg"); //�������� ����
				al_draw_bitmap(image, 0, 0, 0); //���������� ����
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
		//����� �������� ����������

		/*����� ��������� ������������ �������� ������� �� ������������
		��� ����� ���� ������� ������� EV
		*/
		ALLEGRO_EVENT ev;//������������� �������
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) { //����������� �������

		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { //������ �������� ������������� �������
			break;
		}

		/*����� ���� ���� �� ����� ������ ������ ����-��������� ���������� ��������� ���� .*/

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) //���������� �������������� ��� ������� ������������� �� �����
		{

			count_of_clean = 99;
			knopka(size_of_matrix, &Game_on, &size_settings, &game_mode, &game_window, &count_of_clean, b, bouncer_x, bouncer_y);


			/*
			���������� ���� ��������*/
			if (game_window == 0) {

				if ((bouncer_y > 390 && bouncer_y < 430) && (bouncer_x > 420 && bouncer_x < 600)) {//�������� ������� ������ ���������

					al_clear_to_color(al_map_rgb(0, 0, 0));
					if (size_settings == 0) {
						size_settings = 1;

						image = al_load_bitmap("src/res/menu_op.jpg");
						al_draw_bitmap(image, 0, 0, 0);
					}
					else if (size_settings == 1) {
						size_settings = 0;
						image = al_load_bitmap("src/res/fon_menu.jpg");
						al_draw_bitmap(image, 0, 0, 0);
					}
				}
			}
			/*
			������� ������ ������� ���� */
			if (size_settings == 1) {
				size_matrix(&size_of_matrix, bouncer_x, bouncer_y);
			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || //��������� ��������� ���� �� ������������
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) { //���������� ����� �������� ���� ���� ��������� � ������� ����
			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;
			al_flush_event_queue(event_queue);
		}
		if (game_window == 1) {
			//���������� ������� �����
			for (y = 1; y < size_of_matrix; y++) {

				for (x = 1; x < size_of_matrix; x++)
				{
					if (b[x][y] == 1) {
						al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(0, 0, 255));

					}
					else if (b[x][y] == 0) {
						al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(255, 255, 255));
					}
				}
			}

			//��������� �������� �����
			if (game_mode == 3)
			{
				game_mode = 0;


			}
			else if (game_mode == 10 || game_mode == 1)
			{
				if (game_mode == 1) game_mode = 0;
				//���������� ������� �����
				for (y = 1; y < size_of_matrix; y++) {
					for (x = 1; x < size_of_matrix; x++)
					{
						if (b[x][y] == 1) {
							al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(0, 0, 255));

						}
						else if (b[x][y] == 0) {
							al_draw_filled_ellipse(320 + (400 / size_of_matrix) * x, 100 + (400 / size_of_matrix) * y, 160 / size_of_matrix, 160 / size_of_matrix, al_map_rgb(255, 255, 255));
						}
					}
				}
				//���������� �������� ��������� ����
				int i = 0, m = 0;
				for (i = 1; i < 20; ++i) {
					if ((count_of_clean == 5 * i) || (count_of_clean==99))m = 1;
						al_flush_event_queue(event_queue);
				}
				if (m == 1) {

						main_algorithm(b, a, number_of_neighbors, size_of_matrix, &game_mode);



				}
			}

		}

		//��������� ����� ���� �������� �� ������� � ������� ������ �������� ������� ����
		if (game_window == 0) {
			if (size_settings == 1) {
				al_draw_filled_ellipse(650, 390, 5, 5,
					al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 420, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 450, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 480, 5, 5, al_map_rgb(255, 0, 2));

				if (size_of_matrix == 41) al_draw_filled_ellipse(650, 480, 5, 5, al_map_rgb(0, 255, 2));
				if (size_of_matrix == 31) al_draw_filled_ellipse(650, 450, 5, 5, al_map_rgb(0, 255, 2));
				if (size_of_matrix == 21) al_draw_filled_ellipse(650, 420, 5, 5, al_map_rgb(0, 255, 2));
				if (size_of_matrix == 11) al_draw_filled_ellipse(650, 390, 5, 5, al_map_rgb(0, 255, 2));
				al_flip_display();
			}
		}
		al_flip_display();

	}
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_font(font_goldana);
	return 0;


}
