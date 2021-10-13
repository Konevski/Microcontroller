#include <stdio.h>
#include <stdlib.h>

int state = 1;  //the initial state of the predictor
int bit = 1;    //the input bit

int main(){
	switch (state) {   //the main code of the predictor
	case 1:            //strong not-taken
		if (bit == 1) {       
			state = 2;  //switching to weak not-taken
		}
		break;

	case 2:            //weak not-taken
		if (bit == 0) {
			state = 1;   //switching to strong not-taken
		}
		else if (bit == 1) {
			state = 3;    //switching to weak taken
		}
		break;

	case 3:           //strong taken
		if (bit == 0) {
			state = 2;  //switching to weak not-taken
		}
		else if (bit == 1) {
			state = 3;   //switching to strong taken
		}
		break;


	case 4:           //strong taken 
		if (bit == 0) {
			state = 2;   //switching to weak taken
		}
		
		break;
	}

    printf("%d", state);
return 0;
}

