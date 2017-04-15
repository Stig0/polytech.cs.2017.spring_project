SHELL = /bin/sh

PROJECT  := project_name

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
LFLAGS  :=

# ------------
# Targets 
# ------------
default: $(PROJECT)

%.o: %.c
	$(CC) -c -I $(D_SRC) $(CFLAGS) $< -o $@

$(PROJECT): $(FILES_O)
	$(CC) -I $(D_SRC) $(LFLAGS) $(FILES_O) -o $@

.phony:	clean
clean:
	-$(RM) $(FILES_O) $(PROJECT)
