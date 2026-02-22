CC := cc
CFLAGS := -Wall -Wextra -g -fsanitize=address,undefined ../cgs.c
SRCS := $(wildcard *.c)
BINS := $(SRCS:.c=)

.PHONY: all clean

all: $(BINS)
	

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)