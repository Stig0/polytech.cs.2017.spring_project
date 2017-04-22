SHELL = /bin/sh

PROJECT  := GAME_OF_LIFE

# ------------------
# External programs
# ------------------
CC  := gcc
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
CFLAGS  := -Wall
LFLAGS  := *.c

# ------------
# Targets 
# ------------
default: $(PROJECT)

$(PROJECT): $(FILES_O)
	$(CC) $(D_SRC)/$(LFLAGS) -I/allegro5/addons/ -lallegro -lallegro_main -lallegro_image -lallegro_dialog -lallegro_primitives -lallegro_ttf -lallegro_font -o $@ 

clean: 
	-$(RM) $(FILES_O) $(PROJECT)
	
