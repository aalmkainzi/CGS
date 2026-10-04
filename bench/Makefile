CFLAGS := -DNDEBUG -O3 -march=native -flto

bench: bench.c
	/mnt/c/Users/aa.almkainzi/Desktop/projects/slimcc-repo/slimcc -E bench.c -o bench.c.c
	clang bench.c.c ../cgs.c -o bench -O3