CC := cc

ifeq ($(CC), clang)
    CFLAGS := -Wall -Wextra -g -Wno-unused-but-set-variable -Wno-unused-variable -Wno-missing-field-initializers -I.. -lm
else
    CFLAGS := -Wall -Wextra -g  -Wno-unused-but-set-variable -Wno-unused-variable -Wno-missing-field-initializers -I.. -lm
endif

SRCS := $(wildcard *.c)
BINS := $(SRCS:.c=)

.PHONY: all clean

all: $(BINS)
	

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)