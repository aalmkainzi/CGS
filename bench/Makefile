CFLAGS := -DNDEBUG -O3 -march=native -flto

bench: bench.c
	$(CC) $(CFLAGS) bench.c ../cgs.c -o bench 