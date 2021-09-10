#include <stdio.h>



float calGross(float hours, float payrate)
{
	float gross;
	float otgross;
	if (hours > 40.0){
		otgross = (hours-40.0)*(payrate*1.5);
		gross = (40.0 * payrate)+otgross;	
	}

	else {
	gross = ((float)hours)*payrate;
	}

	return (gross);

}


