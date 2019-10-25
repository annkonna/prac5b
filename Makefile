CC = gcc
CFLAGS = -g

encode: encode.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm encode

.PHONY: encode
