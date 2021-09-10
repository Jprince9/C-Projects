/* Defines functions needed to calculate the volumes 
 * of a sphere and cylinder, and perform sumation on floats and angles.
 */
#include <stdio.h>
#ifndef lab3H
#define lab3H

	extern void sphere (float radius, float *surface, float *volume, FILE *outFile);

	extern float volCylinder( float radius, float height);

	extern float sumFloats(float x[], int numFloats, FILE *outFile);

	extern double sinAngle(float angle);

#endif 
