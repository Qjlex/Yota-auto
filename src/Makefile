CC=gcc

yota-auto: socket.o http.o main.o 
	$(CC) -g0 main.o socket.o http.o -o yota-auto
main.o: main.c
	$(CC) -g0 -c main.c -o main.o
http.o: http.c
	$(CC) -g0 -c http.c -o http.o
socket.o: socket.c
	$(CC) -g0 -c socket.c -o socket.o
clean:
	rm -rf *.o yota-auto