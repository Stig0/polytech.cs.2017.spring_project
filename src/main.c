#include <stdio.h> 
#include <allegro5/allegro.h> 
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h> 
#include <allegro5/allegro_image.h> 
#include "allegro5/allegro_native_dialog.h" 

const float FPS = 60;
const int SCREEN_W = 1000;
const int SCREEN_H = 600;
const int BOUNCER_SIZE = 32;
int b1(int b[100][100]);
int b2(int  b[100][100]);
int b3(int  b[100][100]);
int b4(int  b[100][100]);
int l1(int  b[100][100]);
int m = 40;
int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY_MODE *al_get_display_mode(int index, ALLEGRO_DISPLAY_MODE *mode);
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *image = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
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

	ALLEGRO_FONT *font_goldana = al_load_font("Goldana.ttf", 45, 0);
	ALLEGRO_FONT *font_pirulen = al_load_font("pirulen.ttf", 24, 0);

	al_clear_to_color(al_map_rgb(0, 0, 0));



	al_init_primitives_addon();

	al_flip_display();

	al_start_timer(timer);
	int i, j, k, x, h, y = 1, n = 0, f = 0, t = 0;
	int a[100][100], b[100][100];

	int cle = 99;
	int menu = 0, level = 4, lev = 0;
	int kol = 0, kol_max = 300, c1 = 0;
	int life = 0, deaf = 0;
	for (j = 0; j < m; j++) {
		for (i = 0; i < m; i++) {
			b[i][j] = 0;
		}
	}






	int g = 0;

	al_clear_to_color(al_map_rgb(0, 0, 0));


	while (1)
	{
		cle = cle + 1;
		if (cle == 100) {
			cle = 0;



			if (lev == 0) {

				image = al_load_bitmap("fon_menu.jpg");
				al_draw_bitmap(image, 0, 0, 0);
				if (g == 1)
				{
					image = al_load_bitmap("menu_op.jpg");
					al_draw_bitmap(image, 0, 0, 0);
				}//Начало прорисовки меню 

			}
			if (lev == 1) {
				image = al_load_bitmap("play_fon.jpg");//Начало прорисовки меню 
				al_draw_bitmap(image, 0, 0, 0);
				al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 40, 500, 0, "Random");
				al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 180, 500, 0, "Planer");
				al_draw_text(font_goldana, al_map_rgb(255, 0, 0), 320, 500, 0, "Rellay");
				
			}
		}
		//Конец прорисовки меню


		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;

		}



		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (lev == 1) {
				if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 180 && bouncer_x < 330)) {
					f = 10;
					for (j = 0; j < m; j++) {
						for (i = 0; i < m; i++)
							if (b[i][j] > 2) {
								b[i][j] = 0;
							}
					}
				}

				else if
					((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 340 && bouncer_x < 490)) {
					f = 1;
					for (j = 0; j < m; j++) {
						for (i = 0; i < m; i++)
							if (b[i][j] > 2) {
								b[i][j] = 0;
							}
					}

				}
				else if ((bouncer_y
					> 0 && bouncer_y < 80) && (bouncer_x > 500 && bouncer_x < 670)) {
					f = 3;
					for (j = 0; j < m; j++) {
						for (i = 0; i < m; i++)
							if (b[i][j] > 2) {
								b[i][j] = 0;
							}
					}
				}

				else if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 680 && bouncer_x < 840)) {
					for (j = 0; j < m; j++) {
						for (i = 0; i < m; i++) {
							b[i][j] = 0;
						}
					}

				}
				else if ((bouncer_y > 525 && bouncer_y < 600) && (bouncer_x > 800 && bouncer_x < 1000)) {
					lev = 0;
					cle = 99;
				}
				else if ((bouncer_y > 520 && bouncer_y < 550) && (bouncer_x > 10 && bouncer_x < 145)) {
					srand((unsigned)time(NULL));
					for (j = 1; j < m; j++) {

						for (i = 1; i < m; i++) {

							t = rand() % 2;
							b[i][j] = t;
						}
					}
				}
				else if ((bouncer_y > 520 && bouncer_y < 550) && (bouncer_x > 147 && bouncer_x < 279)) {
					for (j = 0; j < m; j++) {
						for (i = 0; i < m; i++) {
							b[i][j] = 0;
						}
					}
					b1(b);
				}
			}
			if (lev == 0) {
				if ((bouncer_y > 350 && bouncer_y < 390) && (bouncer_x > 410 && bouncer_x < 600)) {
					lev = 1;
					g = 0;
					al_clear_to_color(al_map_rgb(0, 0, 0));
					cle = 99;
					for (j = 0; j < m; j++) {
						for (i = 0; i < m; i++) {
							b[i][j] = 0;
						}
					}
					
				}

				if ((bouncer_y > 390 && bouncer_y < 480) && (bouncer_x > 410 && bouncer_x < 600)) {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					if (g == 0) {
						g = 1;

						image = al_load_bitmap("menu_op.jpg");
						al_draw_bitmap(image, 0, 0, 0);
					}
					else if (g == 1) {
						g = 0;
						image = al_load_bitmap("fon_menu.jpg");
						al_draw_bitmap(image, 0, 0, 0);
					}
				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (bouncer_y > 370 && bouncer_y < 405) && (bouncer_x > 640 && bouncer_x < 850)) {
					m = 10;


				}
				else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (bouncer_y > 405 && bouncer_y < 435) && (bouncer_x > 640 && bouncer_x < 850)) {
					m = 20;

				}
				else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (bouncer_y > 435 && bouncer_y < 465) && (bouncer_x > 640 && bouncer_x < 850)) {
					m = 30;

				}
				else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (bouncer_y > 465 && bouncer_y < 495) && (bouncer_x > 640 && bouncer_x < 850)) {
					m = 40;

				}
			}
			if (lev == 1) {
				if ((bouncer_y > 520 && bouncer_y < 550) && (bouncer_x > 280 && bouncer_x < 420)) {
					for (j = 0; j < m; j++) {
						for (i = 0; i < m; i++) {
							b[i][j] = 0;
						}
					}

					b2(b);


				}




				else {

					for (y = 1; y < m; y++) {
						if ((bouncer_y > 100 - 160 / m + (400 / m) * y) && (bouncer_y < 100 + 160 / m + (400 / m) * y))
							for (x = 1; x < m; x++)
							{
								if ((bouncer_x > 320 - 160 / m + (400 / m) * x) && (bouncer_x < 320 + 160 / m + (400 / m) * x)) {
									if (b[x][y] == 1) {
										b[x][y] = 0;
										kol--;

									}
									else if ((b[x][y] == 0) && kol < kol_max) {
										b[x][y] = 1;
										kol++;
									}
									else if ((b[x][y] == 3) && kol < kol_max) {
										b[x][y] = 1;
										kol++;

									}
								}

							}
					}
				}
			}
		}
		if (lev == 1) {
			for (y = 1; y < m; y++) {

				for (x = 1; x < m; x++)
				{
					if (b[x][y] == 1) {
						al_draw_filled_ellipse(320 + (400 / m) * x, 100 + (400 / m) * y, 160 / m, 160 / m, al_map_rgb(0, 0, 255));
						redraw = true;
					}
					else if (b[x][y] == 0) {
						al_draw_filled_ellipse(320 + (400 / m) * x, 100 + (400 / m) * y, 160 / m, 160 / m, al_map_rgb(255, 255, 255));
					}
					else if (b[x][y] == 3) {
						al_draw_filled_ellipse(320 + (400 / m) * x, 100 + (400 / m) * y, 160 / m, 160 / m, al_map_rgb(0, 255, 0));
					}
					else if (b[x][y] == 2) {
						al_draw_filled_ellipse(320 + (400 / m) * x, 100 + (400 / m) * y, 160 / m, 160 / m, al_map_rgb(255, 0, 2));
					}
				}
			}


			if (f == 3)
			{
				f = 0;


			}
			else if (f == 10 || f == 1)
			{
				if (f == 1) f = 0;

				for (y = 1; y < m; y++) {

					for (x = 1; x < m; x++)
					{
						if (b[x][y] == 1) {
							al_draw_filled_ellipse(320 + (400 / m) * x, 100 + (400 / m) * y, 160 / m, 160 / m, al_map_rgb(0, 0, 255));
							redraw = true;
						}
						else if (b[x][y] == 0) {
							al_draw_filled_ellipse(320 + (400 / m) * x, 100 + (400 / m) * y, 160 / m, 160 / m, al_map_rgb(255, 255, 255));
						}
						else if (b[x][y] == 3) {
							al_draw_filled_ellipse(320 + (400 / m) * x, 100 + (400 / m) * y, 160 / m, 160 / m, al_map_rgb(0, 255, 0));
						}
						else if (b[x][y] == 2) {
							al_draw_filled_ellipse(320 + (400 / m) * x, 100 + (400 / m) * y, 160 / m, 160 / m, al_map_rgb(255, 0, 2));
						}
					}
				}
				for (j = 1; j < m; j++) {
					for (i = 1; i < m; i++) {
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
							if ((k == 2) || (k == 3)) a[i][j] = 1;
							else a[i][j] = 0;
						}
						if (b[i][j] == 0) {
							if ((k == 3)) a[i][j] = 1;
							else a[i][j] = 0;
						}
						if (b[i][j] == 2) {
							if ((k == 3)) a[i][j] = 1;
							else if (b[i][j] == 0) a[i][j] = 0;
							else a[i][j] = 2;
						}
						k = 0;
					}
				}
				int d = 0;
				for (y = 1; y < m; y++) {
					for (x = 1; x < m; x++)
					{
						if (b[x][y] == a[x][y]) d++;

					}
				}
				if (d > m*m - 2 * m) { d = 0; f = 0; }


				for (y = 1; y < m; y++) {
					for (x = 1; x < m; x++)
					{
						b[x][y] = a[x][y];
						redraw = true;
					}
				}

			}

		}

		if (lev == 0) {
			if (g == 1) {
				al_draw_filled_ellipse(650, 390, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 420, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 450, 5, 5, al_map_rgb(255, 0, 2));
				al_draw_filled_ellipse(650, 480, 5, 5, al_map_rgb(255, 0, 2));
			}
			if (m == 40 && g == 1) al_draw_filled_ellipse(650, 480, 5, 5, al_map_rgb(0, 255, 2));
			if (m == 30 && g == 1) al_draw_filled_ellipse(650, 450, 5, 5, al_map_rgb(0, 255, 2));
			if (m == 20 && g == 1) al_draw_filled_ellipse(650, 420, 5, 5, al_map_rgb(0, 255, 2));
			if (m == 10 && g == 1) al_draw_filled_ellipse(650, 390, 5, 5, al_map_rgb(0, 255, 2));
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
