main.o: main.c  
	gcc ./main.c ./functions.c -I/allegro5/addons/ -lallegro -lallegro_main -lallegro_image -lallegro_dialog -lallegro_primitives -lallegro_ttf -lallegro_font
