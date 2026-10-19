CC = gcc
CFLAGS = -std=c11 -Wall -Wextra
TARGET = date_pair_nl
SOURCE = date_pair_nl.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

.PHONY: clean
