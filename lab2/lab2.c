/*************************************************************
 **Joshua Prince
 **COSC 2347 01 Special Topics-Programming
 **Lab 2 -- 'A' option
 **02/05/2021
 
 
 **Version 1.0
*************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calGross(float, float);
float calTax(float ytd, float taxLimit, float gross, float FICArate);
void newpg(FILE *outFile, int *LK, int *PK, float pgGross, float pgFICA, float pgNet);

int main(){


FILE *inFile;
FILE *outFile;

//IO files and overwrite response
char inName[21];
char outName[21];
char response;

//variables within input file
int empID;
char firstName[15], lastName[15], department[6], deptkey[6];
float ytd, payrate, hours;

//page/control break variables
int PK = 0, LK = 0, maxLine = 4;
float grossTotal = 0, FICATotal = 0, netTotal = 0;
float deptFICA = 0, deptGross = 0, deptNet = 0;
float pgGross = 0, pgFICA = 0, pgNet = 0;

//variables for calculating gross,ytd,fica
float gross, newYTD, FICA, net;
float FICArate = .071;
int taxLimit = 110100;

printf("Enter the input file name with path ");
scanf("%s", inName);
inFile = fopen(inName, "r" );

if( inFile == NULL){ //if input file doesnt exit
	printf("input file not found");
	exit(1);
}//end input file doesnt exit

printf("Enter the output file name with path ");
scanf("%s", outName);

if ((outFile = fopen(outName, "r")) != NULL){//output file exists
	printf("Output file already exists, do you wish to overwrite? (Y/N)");
	scanf("%*c %c", &response);

	if ((response == 'n') || (response == 'N')){// if not overwriting
		fclose(outFile);
		printf("File not overwritten, program exitting");
		exit(1);
	}//end if not overwriting
}//end output file exists


outFile = fopen(outName, "w");

while((fscanf(inFile, "%i", &empID)) != EOF){//reads file until end
	fscanf(inFile, "%s %s %s", lastName, firstName, department);
	fscanf(inFile, " %f %f %f", &ytd, &payrate, &hours);

	if (PK == 0){//write first page header
		strcpy(deptkey, department);
		PK++;
		fprintf(outFile, "%50s \n", "ACME Sports INC.");
		fprintf(outFile, "%60s \n\n", "We are the best, you use the best!");
		fprintf(outFile, "%45s \n", "ACME");
		fprintf(outFile, "%-15s %-15s %-9s", "Emp No.", "Name", "Dept");
		fprintf(outFile, "%-2s %11s %11s %11s \n\n", "New YTD", "Gross", "FICA", "Net");\
		LK = 0;
	}//end write first page header
	
	if (strcmp(deptkey, department) != 0){//if new department
		fprintf(outFile, "\n %-48s %11.2f %11.2f %11.2f \n\n", "Dept Totals", deptGross, deptFICA, deptNet);
		deptGross = 0;
		deptNet = 0;
		deptFICA = 0;
		strcpy(deptkey, department);
	}//end if new department
	if (LK == maxLine){//if end of page, end page and create new page
		
		newpg(outFile, &LK, &PK, pgGross, pgFICA, pgNet); 
		pgGross = 0;
		pgNet = 0;	
		pgFICA = 0;
	}//end if end of page
		
	
	//calculate gross, tax, net, newytd , increase line count
	gross = calGross(hours, payrate);
	FICA = calTax(ytd, taxLimit, gross, FICArate);
	net = gross - FICA;
	newYTD = ytd + net;
	
	//writes detail lines
	fprintf(outFile, "%-9d %-9s %-11s %-6s", empID, lastName, firstName, department);
	fprintf(outFile, "%11.2f %11.2f %11.2f %11.2f \n", newYTD, gross, FICA, net);
	LK++;

	//calculate page totals
	pgGross = pgGross + gross;
	pgNet = pgNet + net;
	pgFICA = pgFICA + FICA;
		
	//calculate final totals
	grossTotal = grossTotal + gross;
	FICATotal = FICATotal + FICA;
	netTotal = netTotal + net;

	//calculate department totals
	deptGross = deptGross + gross;
	deptFICA = deptFICA + FICA;
	deptNet = deptNet + net;
}//end while not EOF

fprintf(outFile, "%-49s %11.2f %11.2f %11.f \n", "Dept Total", deptGross, deptFICA, deptNet);
fprintf(outFile, "\n %-48s %11.2f %11.2f %11.2f", "Page Totals", pgGross, pgFICA, pgNet);
fprintf(outFile, "\n %s %-3i \n", "Pg: ", PK);
PK++;
fprintf(outFile, "\f \n %s", "------------------");
fprintf(outFile, "\n %50s \n", "Reports Summary");
fprintf(outFile, "%-10s %18.2f \n", "Total Gross: ", grossTotal);
fprintf(outFile, "%-10s %19.2f \n", "Total FICA: ", FICATotal);
fprintf(outFile, "%-10s %20.2f \n", "Total Net: ", netTotal);
fprintf(outFile, "%s %-3i", "Pg: ", PK);

}//end main
