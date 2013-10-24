CC=gcc

yota-auto: string.o socket.o http.o main.o 
	$(CC) -g0 main.o string.o socket.o http.o -o yota-auto
main.o: main.c
	$(CC) -g0 -c main.c -o main.o
http.o: http.c
	$(CC) -g0 -c http.c -o http.o
socket.o: socket.c
	$(CC) -g0 -c socket.c -o socket.o
string.o: string.c
	$(CC) -g0 -c string.c -o string.o
clean:
	rm -rf *.o yota-auto