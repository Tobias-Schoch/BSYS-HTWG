TARGET = chap6_1 chap6_2
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=gnu17

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm -f $(TARGET)
	echo clean done
