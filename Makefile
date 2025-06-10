CC = gcc
CFLAGS = -Wall -Iinclude

SRC = main.c src/render.c src/rotate.c
OBJ = $(SRC:.c=.o)
OUT = donut

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)
