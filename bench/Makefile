CFLAGS := -DNDEBUG -O3 -march=native

bench: bench.c
	/mnt/c/Users/aa.almkainzi/Desktop/projects/slimcc-repo/slimcc -DNDEBUG -E bench.c -o bench.c.c
	clang $(CFLAGS) bench.c.c ../cgs.c -o bench
