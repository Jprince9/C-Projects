/*************************************************************
 **Joshua Prince
 **COSC 2347 01 Special Topics-Programming
 **Lab 1 -- 'A' option
 **02/05/2021


 **Version 2.0
**************************************************************/




#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <monetary.h>

int main(){


FILE *inFile;
FILE *outFile;
char inName[21]="lab1in.txt";
char outName[21]="lab1out.txt";

int lineNum =0;
int employeeID;
int taxLimit = 110100;
float ytd, gross;
float FICArate = .042;
float FICA=0;
float grossTotal=0;
float FICATotal=0;


char firstName[10],lastName[10];

inFile = fopen(inName, "r");

if((outFile = fopen(outName, "r")) != NULL) {
//using the input file to enter and calculate//
//
printf("output file already exists, program exiting");
fclose(outFile);
exit(1);}

outFile = fopen(outName, "w");
fprintf(outFile,"%50s \n\n", "ACME");
fprintf(outFile,"%-15s %-13s %-16s %-4s %14s %16s %15s\n\n", "Line No.", "Emp. ID", "First Name", "Last Name", "YTD($)", "Gross($)", "FICA");
while((fscanf(inFile, "%d", &employeeID)) != EOF){

	fscanf(inFile, "%s %s", firstName, lastName);
	fscanf(inFile, "%f", &ytd);
	fscanf(inFile, "%f", &gross);
	if (ytd>=taxLimit){ //pay no tax
		FICA = 0;
		fprintf(outFile, "%-15d %-13d %-16s %-7s",lineNum, employeeID, firstName, lastName); //left aligned
		fprintf(outFile, "%17.2f %16.2f %10s %8.2f\n", ytd, gross, "$", FICA); //right aligned
		grossTotal = grossTotal+gross;
		FICATotal = FICATotal+FICA;
		lineNum++;
	}
	else if (ytd+gross<=taxLimit){ //pay tax on total gross
		FICA =FICArate * gross;
		fprintf(outFile, "%-15d %-13d %-16s %-7s",lineNum, employeeID, firstName, lastName); //left aligned
		fprintf(outFile, "%17.2f %16.2f %10s %8.2f \n", ytd, gross, "$",FICA); //right aligned
		grossTotal = grossTotal+gross;
		FICATotal = FICATotal+FICA;
		lineNum++;
	}
	else { //pay tax on (taxLimit -ytd)
		FICA = (taxLimit-ytd)*FICArate;
		fprintf(outFile, "%-15d %-13d %-16s %-7s",lineNum, employeeID, firstName, lastName); //left aligned
		fprintf(outFile, "%17.2f %16.2f %10s %8.2f\n", ytd, gross, "$", FICA); // right aligned
		grossTotal = grossTotal+gross;
		FICATotal = FICATotal+FICA;
		lineNum++;
	}
}
fprintf(outFile, "\n\n %70s %16.2f %19.2f\n", "Totals:", grossTotal, FICATotal);

}
