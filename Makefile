SHELL = /bin/sh 

PROJECT  := GAME_OF_LIFE

# ------------------
# External programs
# ------------------
CC  := gcc -g -w
RM  := rm -rf

# --------------------
# Directories & Files
# --------------------
D_SRC    := ./src
FILES_C  := $(wildcard $(D_SRC)/*.c)
FILES_O  := $(FILES_C:.c=.o)

# ------------
# Flags 
# ------------
CFLAGS  := -lm
LFLAGS  := 

# ------------
# Targets 
# ------------
	#$(CC) -c -I. $(D_SRC) -L. -lallegro -o $@
	#$(CC) -c -I $(LIBS) $(D_SRC) $(CFLAGS) $< -o  $@
default: $(PROJECT)
%.o: %.c
	$(CC) -c -I $(D_SRC) $(CFLAGS) $< -o  $@

$(PROJECT): $(FILES_O)
	$(CC) -I $(D_SRC) $(LFLAGS) $(FILES_O) -I/allegro5/addons/ -lallegro -lallegro_main -lallegro_image -lallegro_dialog -lallegro_primitives -lallegro_ttf -lallegro_font -o $@ -lm
.phony:	clean
clean:
	-$(RM) $(FILES_O) $(PROJECT)
	
