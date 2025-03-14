#include<math.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void addition(float, float);
void subtraction(float, float);
void multiplication(float, float);
void division(float, float);

float getInput();

void print(float);


void main(){
	int choice, choice2, check = 0;
	float x, y;
	printf("This program is a simple calculator.\n");
	while(check != 1){
    	printf("Which would you like to do?: (1) Addition (2) Subtraction (3) Multiplication (4) Division: ");
    	scanf("%1d", &choice);
    	switch(choice){
    		case 1: 
    			x = getInput();
    			y = getInput();
    			addition(x, y);
    			break;
    		case 2:
    			x = getInput();
    			y = getInput();
    			subtraction(x, y);
    			break;
    		case 3: 
	    		x = getInput();
	    		y = getInput();
	    		multiplication(x, y);
	    		break;
	    	case 4:
	    		x = getInput();
	    		y = getInput();
	    		division(x, y);
	    		break;
	    	default:
	    		printf("Not a valid choice.\nExiting program...");
	    		sleep(3);
	    		exit(1);
    	}
    	printf("\nCalculate another? (1) Yis (2) Naurr: ");
    	scanf(" %d", &choice2);
    	if(choice2 == 2){
        	check = 1;
    	}
	}
}

float getInput(){
	float x;
	printf("Enter number: ");
	scanf(" %f", &x);
	return x;
}

void addition(float x, float y){
	float result = x + y;
	print(result);
}

void subtraction(float x, float y){
	float result = x - y;
	print(result);
}

void multiplication(float x, float y){
	float result = x * y;
	print(result);
}
void division(float x, float y){
	float result = x / y;
	print(result);
}

void print(float result){
	printf("\nThe result is: %.2f", result);
}

	
