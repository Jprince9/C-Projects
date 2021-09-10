#$cat lab4build.sh


#scipt to build lab4 application

gcc -c randapi.c

ar -cru librandapi.a randapi.o

gcc -o lab4c lab4c.c -L. -lrandapi -lm

./lab4c
