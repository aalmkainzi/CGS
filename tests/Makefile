CFLAGS  := -ggdb -fsanitize=address,undefined -std=c23
SRCS    := test1.c test2.c test3.c
OBJS    := $(SRCS:.c=.o)
DEPS    := ../cgs.c ../cgs.h test_common.h

.PHONY: all clean

all: test

test: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) test