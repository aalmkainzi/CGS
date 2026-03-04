CC := cc
SRCS := $(wildcard *.c)
CFLAGS := -Wall -Wextra -I../.. -ggdb


.PHONY: all clean

all: a.out
	

a.out: $(SRCS)
	$(CC) $(CFLAGS) $^

clean:
	rm a.out