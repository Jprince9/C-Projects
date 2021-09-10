lab2main: lab2.o calTax.o calgross.o newpg.o 
	gcc -o lab2main lab2.o calTax.o calgross.o newpg.o

#Chain rules

lab2.o: lab2.c
	gcc -c -o lab2.o lab2.c

calTax.o: src/PayrollMain/Tax/calTax.c
	gcc -c -o calTax.o src/PayrollMain/Tax/calTax.c

calgross.o: src/PayrollMain/Gross/calgross.c
	gcc -c -o calgross.o src/PayrollMain/Gross/calgross.c

newpg.o: src/PayrollMain/NewPage/newpg.c
	gcc -c -o newpg.o src/PayrollMain/NewPage/newpg.c





