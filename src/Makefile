CC=gcc
obj_flags=-g -c

yota-auto: string.o socket.o http.o main.o 
	$(CC) main.o string.o socket.o http.o -o yota-auto
main.o: main.c
	$(CC) $(obj_flags) main.c -o main.o
http.o: http.c
	$(CC) $(obj_flags) http.c -o http.o
socket.o: socket.c
	$(CC) $(obj_flags) socket.c -o socket.o
string.o: string.c
	$(CC) $(obj_flags) string.c -o string.o
clean:
	rm -rf *.o yota-auto