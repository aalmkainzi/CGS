build_cmnd = cc -Wall -Wextra -g -fsanitize=address,undefined ../fxs.c

all: $(wildcard *.c)
	$(build_cmnd) string_buffer.c -o string_buffer
	$(build_cmnd) mutstr_ref.c    -o mutstr_ref
	$(build_cmnd) split_join.c    -o split_join
	$(build_cmnd) string_view.c   -o string_view
	$(build_cmnd) dstring.c       -o dstring