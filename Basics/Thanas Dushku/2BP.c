#include <stdio.h>
#include <stdlib.h>

int state = 1;  //the initial state of the predictor
int event = 1;  //the input event

void control(int event){
	switch (state) {   //the main code of the predictor
	case 1:            //strong not-taken
		if (event == 1) {       
			state = 2;  //switching to weak not-taken
		}
		break;

	case 2:            //weak not-taken
		if (event == 0) {
			state = 1;   //switching to strong not-taken
		}
		else if (event == 1) {
			state = 3;    //switching to weak taken
		}
		break;

	case 3:           //weak taken
		if (event == 0) {
			state = 2;  //switching to weak not-taken
		}
		else if (event == 1) {
			state = 3;   //switching to strong taken
		}
		break;


	case 4:           //strong taken 
		if (event == 0) {
			state = 2;   //switching to weak taken
		}
		
		break;
	}

    printf("%d", state);
return 0;
}

