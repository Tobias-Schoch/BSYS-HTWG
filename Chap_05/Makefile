TARGET = chap5_1 chap5_2 chap5_3 chap5_4 chap5_5 chap5_6 chap5_7 chap5_8
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=gnu17

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm -f $(TARGET)
	echo clean done
