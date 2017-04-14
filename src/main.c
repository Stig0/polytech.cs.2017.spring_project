#include <stdio.h> 
#include <allegro5/allegro.h> 
#include <allegro5\allegro_primitives.h> 
#include <allegro5\allegro_font.h> 
#include <allegro5\allegro_ttf.h> 
#include <allegro5/allegro_image.h> 
#include "allegro5/allegro_native_dialog.h" 

const float FPS = 60; 
const int SCREEN_W = 840; 
const int SCREEN_H = 580; 
const int BOUNCER_SIZE = 32; 
int b1(int b[20][20]); 
int b2(int b[20][20]); 
int b3(int b[20][20]); 
int b4(int b[20][20]); 
int l1(int b[20][20]); 
int m = 20; 
int main(int argc, char **argv) 
{ 
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


al_clear_to_color(al_map_rgb(0, 0, 0)); 



al_init_primitives_addon(); 

al_flip_display(); 

al_start_timer(timer); 
int i, j, k, x, h, y = 1, n = 0, f = 0, t = 0; 
int a[100][100], b[20][20]; 

int cle=0; 
int menu=0, level=4,lev=0; 
int kol = 0, kol_max = 300,c1=0; 
int life = 0, deaf = 0; 
for (j = 0; j < m; j++) { 
for (i = 0; i < m; i++) { 
b[i][j] = 0; 
} 
} 





image = al_load_bitmap("startstepstopclean2.png"); 
al_draw_bitmap(image, 0, 0, 0); 

image = al_load_bitmap("rules4.png"); 
al_draw_bitmap(image, 510, 80, 0); 

image = al_load_bitmap("randomplanerrellay.png"); 
al_draw_bitmap(image, 10, 520, 0); 

al_draw_filled_rectangle(10, 100, 110, 120, al_map_rgb(500, 0, 255)); 
