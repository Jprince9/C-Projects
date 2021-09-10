#include <stdio.h>

void newpg(FILE *outFile, int *LK, int *PK, float pgGross, float pgFICA, float pgNet){

	
			
	fprintf(outFile, "\n %-48s %11.2f %11.2f %11.2f \n", "Page Totals", pgGross, pgFICA, pgNet);
	fprintf(outFile, "\n %s %-3d \n", "Pg: ", *PK);
	*PK = *PK + 1;
 	
	fprintf(outFile,"\f %s \n\n", "-----------------------------");
	fprintf(outFile,"%45s \n", "ACME");
	fprintf(outFile,"%-15s %-15s %-9s", "Emp No.", "Name", "Dept");
	fprintf(outFile, "%-2s %11s %11s %11s \n\n", "New YTD", "Gross", "FICA", "Net");

	*LK = 0;


//	printf("\nValue of LK : %i\n", *LK);
}







