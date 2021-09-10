$cat buildlab2.sh
#Script to build lab2 application


gcc -c -o calgross.o src/PayrollMain/Gross/calgross.c

gcc -c -o calTax.o src/PayrollMain/Tax/calTax.c

gcc -c -o newpg.o src/PayrollMain/NewPage/newpg.c

gcc -c -o lab2.o lab2.c

gcc -o lab2main lab2.o calgross.o calTax.o newpg.o


