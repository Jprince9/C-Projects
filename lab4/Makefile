lab4main: lab4c.c librandapi.so
	gcc -o lab4main lab4c.c -L -librandapi -lm


#Chain Rules

lab4c.o: lab4c.c
	gcc -c -o lab4c.o lab4c.c

randapi.o: randapi.c
	gcc -fPIC -c -o randapi.o randapi.c

librandapi.so: randapi.o
	gcc -shared -o librandapi.so randapi.o
