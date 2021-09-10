/************************************************************************
 * Joshua Prince
 * COSC 2347 01 Special Topics Programming
 * Lab 4 - 'C' Option
 *
 * Date 4/14/2021
 *
 * Version 1.0
*************************************************************************/



#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <wait.h>
#include <time.h>
#include <sys/types.h>
#include <stdbool.h>
#include "randapi.h"

#define Maxlength 80
#define PipeStdIn 0
#define PipeStdOut 1
#define Numiterations 1234567L



int main(){

int myPipes[2];
char buffer[Maxlength +1];
if(pipe(myPipes) == 0){//pipe created
	if(fork() == 0){//creates child 1
		if(fork() == 0){//creates child 2
			//get the random exponentials, 5 seconds mean for life support, 4 second mean for lights and temp
			if(fork() == 0){//creates child 3
				//child 3 info
				float sleeplife = 0.0;
				float lifesum = 0.0;
				while (true){
					seedRandGenerator();
					for (int k = 0; k<Numiterations; k++){
						lifesum += (getRandExponential() * 5.0);
						sleeplife = (lifesum / (float)(Numiterations));
					}//end for
					sleep(sleeplife);				
					const char *lifesupport ={"adjusted life support\n"};
					write(myPipes[PipeStdOut], lifesupport ,strlen(lifesupport)+1);
				}//end child 3 while
			}//end child 3 info
			else{
				//child 2 info
				float sleeplights = 0.0;
				float lightsum = 0.0;
				while(true){
					seedRandGenerator();
					for (int k = 0; k<Numiterations; k++){
						lightsum += (getRandExponential() * 4.0);
						sleeplights = (lightsum / (float)(Numiterations));
					}//end for
					sleep(sleeplights);
					const char *lights = {"adjusted lighting and temperature\n"};
					write(myPipes[PipeStdOut], lights, strlen(lights)+1);
				}//end child 2 while	
			}//end child 2 info
		}
		else {
			//child 1 info
			long sleepnav = 0L;
			float navsum = 0.0;
			while (true){
				seedRandGenerator();			
				for(int k = 0; k< Numiterations; k++){
					navsum += getRandInteger(6);
					sleepnav = (navsum / (float)(Numiterations));
				}//end for
				sleep(sleepnav);
				const char *nav = {"adjusted navigation\n"};
				write(myPipes[PipeStdOut], nav, strlen(nav) +1);
			}//end while
		}//end child 1 info
	}//end child 1 2 and 3 creation
	else{
		//parent info
		while (true){			
			read(myPipes[PipeStdIn], buffer, Maxlength);
			printf("message from systems to bridge %s \n", buffer);
			time_t currentTime;
			time(&currentTime);
			printf("%s\n", ctime(&currentTime));
		}//end while
	}//end else

}//end if

}//end main

