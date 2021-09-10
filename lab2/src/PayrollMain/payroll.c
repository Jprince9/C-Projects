#include <stdio.h>

double calGross(int, double);
double calTax(double, double);

int main(){
	int hours;
	float payRate;
	double taxRate;
	double gross,tax,net;

	gross = calGross(hours, payRate);
	tax = calTax(gross, taxRate);

	net = gross-tax;

}




