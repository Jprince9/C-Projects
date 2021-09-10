/*********************************************************
**Joshua Prince
**COSC 2347 01 Special Topics - Programming
**Lab3 -- 'A' option
**
**Date - 3/22/2021

**Version 1.0
*********************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "lab3lib.h"


int main(){


FILE *outFile;

char outName[21] = "lab3outputs.txt";


outFile = fopen(outName, "w");

float vol, radius, angle, height, volume=0, surface=0, sinangle, sum, temp;
int numFloats = 8,i=0, j=0, k=0, pt;
float x[numFloats];

//calculate the sphere


printf("Enter the radius of the sphere "); scanf("%f", &radius);

sphere(radius, &surface, &volume, outFile);


//calculate the cylinder
printf("\n Enter the radius of the cylinder "); scanf("%f", &radius);
printf("\n Enter the height of the cylinder "); scanf("%f", &height);

	vol = volCylinder(radius, height);

printf("\n %s %f \n", "The volume of the cylinder is ", vol);
fprintf(outFile, "\n %s %f \n", "The volume of the cylinder is ", vol);

//calculate sum of floats
//printf("\nHow many floating point numbers would you like to add? "); scanf("%d", &numFloats);
for (k=0; k < numFloats; k++){
	printf("\n enter number to add "); scanf("%f", &x[k]);
}
printf("\nthe numbers in unsorted order are ");
fprintf(outFile, "\n the numbers in unsorted order are ");
for (i = 0; i < numFloats; i++){
	printf("\n %f", x[i]);
	fprintf(outFile, "\n %f", x[i]);
}
sum = sumFloats(x, numFloats, outFile);

printf("\n the numbers in sorted order are ");
fprintf(outFile, "\n the numbers in sorted order are ");
for (i = 0; i < numFloats; i++){
	printf("\n %f", x[i]);
	fprintf(outFile, "\n %f", x[i]);
}
printf("\n The sum of all the floating point numbers is ");
printf("%f \n ", sum);
fprintf(outFile, "\n %s %f \n", "The sum of all floating point numbers is ", sum);


//calculate sin of angles

for(k = 0; k < 3; k++ ){
	printf("\n Enter the angle "); scanf("%f", &angle);
	
	sinangle = sinAngle(angle); 
	
	printf("\n %s %f %s %f", "The sin of ", angle, "is ", sinangle);
	fprintf(outFile, "\n %s %f %s %f", "The sin of ", angle, "is ", sinangle);
	
}//end while


}//end main







