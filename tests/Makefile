CC := cc

ifeq ($(CC), clang)
    CFLAGS := -Wall -Wextra -Wno-unused-value -Wno-unused-but-set-variable -Wno-unused-variable -Wno-missing-field-initializers -I.. -lm -ggdb -std=c23
else
    CFLAGS := -Wall -Wextra -Wno-unused-value -Wno-unused-but-set-variable -Wno-unused-variable -Wno-missing-field-initializers -I.. -lm -ggdb -std=c23 -fsanitize=address,undefined
endif

SRCS := $(wildcard *.c)
BINS := $(SRCS:.c=)

.PHONY: all clean

all: $(BINS)
	

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)