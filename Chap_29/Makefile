TARGET = binaretree binarytreeHoh linkedlist linkedListHoH
CC = clang
CFLAGS = -pthread -Wall -Wextra -Wpedantic -std=gnu17

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm -f $(TARGET)
	echo clean done
