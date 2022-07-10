all:
	gcc -g -Icompress -Idecompress compress/* decompress/* *.c -o test

test: all
	./test