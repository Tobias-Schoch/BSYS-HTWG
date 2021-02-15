TARGET = memory-user
CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -std=gnu17

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm -f $(TARGET)
	echo clean done
