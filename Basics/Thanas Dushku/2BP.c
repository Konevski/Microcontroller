#include <stdio.h>
#include <stdlib.h>
#define strongNotTaken 0
#define weakNotTaken 1
#define weakTaken 2
#define strongTaken 3

int state = strongNotTaken;  //the initial state of the predictor
int event = 1;  //the input event

void control(int event){
	switch (state) {     //the main code of the predictor
	case strongNotTaken:         
		if (event == 1) {       
			state = weakNotTaken;  //switching to weak not-taken
		}
		break;

	case weakNotTaken:        
		if (event == 0) {
			state = strongNotTaken;   //switching to strong not-taken
		}
		else if (event == 1) {
			state = weakTaken;    //switching to weak taken
		}
		break;

	case weakTaken:        
		if (event == 0) {
			state = weakNotTaken;  //switching to weak not-taken
		}
		else if (event == 1) {
			state = strongTaken;   //switching to strong taken
		}
		break;


	case strongTaken:           
		if (event == 0) {
			state = weakTaken;   //switching to weak taken
		}
		
		break;
	}

    printf("%d", state);
	return;
}

