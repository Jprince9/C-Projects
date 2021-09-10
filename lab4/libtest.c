#include "randapi.h"
#include <stdio.h>

#define nums 1234567L

int main(){
	long k,longsum;
	double floatsum;

	longsum= 0L;
	for (k = 0; k<nums; k++){
		longsum += getRandInteger(20);
	}
		printf("average random int is %d\n", (int)(longsum/numiterations));


floatsum = 0.0;
for (k = 0; k<nums; k++){
	floatsum += getRandFloat()l
}
printf("average random float = %f ]n", floatsum/(float)numiterations));



}
