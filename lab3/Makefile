lab3main: lab3.c liblab3lib.so
	gcc -o lab3main lab3.c -L. -llab3lib -lm


#Chain rules


lab3.o: lab3.c
	gcc -c -o lab3.o lab3.c

lab3lib.o: lab3lib.c
	gcc -fPIC -c -o lab3lib.o lab3lib.c

liblab3lib.so: lab3lib.o
	gcc -shared -o liblab3lib.so lab3lib.o


