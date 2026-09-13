CC := cc
BASE_CFLAGS := -Wall -Wextra -g -I.. ../cgs.c -std=c23
SRCS := $(wildcard *.c)
BINS := $(SRCS:.c=)

.PHONY: all clean

all: $(BINS)
	

%: %.c
	$(CC) $(BASE_CFLAGS) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)