#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define epsilon .000001


//calculates volume and surface area of sphere
void sphere(float radius, float *surface, float *volume, FILE *outFile){
	
	*surface = 4.0 * (M_PI) * pow(radius, 2);
	*volume = (4.0/3.0) * (M_PI) * pow(radius,3);
	printf("\n %s %2.2f \n", "the volume of the sphere is", *volume);
	printf("%s %2.2f\n", "the surface area of the sphere is", *surface);
	fprintf(outFile, "\n %s %2.2f \n", "the volume of the sphere is", *volume);
	fprintf(outFile, "%s %2.2f \n", " the surface area of the sphere is", *surface);
}//end sphere


//calculates volume of cylinder
float volCylinder(float radius, float height){
	

	return ((M_PI) * pow(radius,2) * height);
}//end volCylinder


//calculates the total of an array of floats
float sumFloats(float x[], int numFloats, FILE *outFile){
	float sum, temp;
	int i, k, j, pt;
	//printf("The numbers to add in unsorted order are ");
	//fprintf(outFile, "The numbers to add in unsorted order are ");
	//for (i = 0; i <(numFloats-1); i++){
	//	temp = x[i];
	//	fprintf(outFile,"%f", x[i]);
	//	printf("%f", x[i]);
	//	i++;
	//}
	//sort the array
	for (j = 0; j < (numFloats-1); j++){
		pt = j;
		k = j+1;

		while (k < numFloats){
			if (x[pt] > x[k]){
				pt = k;
			}
			else
				k = k+1;
		}//end while
		temp = x[j];
		x[j] = x[pt];
		x[pt] = temp;
	}//end for

	for (k = 0; k < numFloats; k++){//calculates sum of each item in array
		sum = sum + x[k];
	}//end for

	return (sum);
}//end sumFloats


//calculates the radian of an angle
double sinAngle(float angle){
	float guess;
	int fact(int n){
		if (n == 0 || n == 1){
			return (1);
		}
		else 
			return (n*fact(n-1));
	}//end int fact(int n)
	int n = 0;
	int m = 1;
	float x = (angle * ( (M_PI) / 180));	
	while ( fabs((((pow(-1, n) * pow(x, (2 * n) +1) / fact((2 * n) +1)))   +   ((pow(-1, m) * pow(x, (2 * m) +1)) / fact((2 * m) + 1))  ))  > epsilon){
	
	 guess += ( pow(-1, n) * pow(x, (2 * n) +1)) / fact((2 * n) +1);
	 //(angle * ( (M_PI) / 180.0));
	 //printf("factorials %d \n", fact((2 * n) +1));
	 n++;
	 m++;
	 //printf("\nguess value is : %f",guess);
	
	 }
	return (guess);
	//else
	//	return (-1.0);
	    
}//end sin



