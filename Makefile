all:
	gcc -Icompress -Idecompress compress/* decompress/* *.c -o test
