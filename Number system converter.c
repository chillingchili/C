#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int askQues();
void conDecBin(int, char *);
void conDecOct(int, char *);
void conDecHex(int, char *);


void main(){
	
	int i, len, dec, numInt;
	char num[32], final[32];
		
	dec = askQues();

	printf("Enter number to convert: ");
	scanf("%s", &num);


	switch(dec){
		case 6: 
			numInt = atoi(num);
			conDecBin(numInt, final);
			printf("\nYour converted binary is: %s", final);
			break;
		case 8:
			numInt = atoi(num);
			conDecOct(numInt, final);
			printf("\nYour converted octal number is: %s", final);
			break;
		case 9:
			numInt = atoi(num);
			conDecHex(numInt, final);
			printf("\nYour converted hexadecimal number is: %s", final);
			break;
		default: 
			printf("Not available yet"); 
	}
	
	
}

void conDecBin(int num, char *final){
	int i = 0, bin, j;
	char arr[32];
	while(num != 0){
		bin = num % 2;
		num = num / 2;
		if(bin == 1){
			arr[i] = '1';	
		} else {
			arr[i] = '0';
		}
		i++;
	}
	for(j = 0; j < i; j++){
		final[j] =  arr[i - j -1];
	}
	final[j] = '\0';
}

void conDecOct(int num, char *final){
	int i = 0, oct, j;
	char arr[32];
	while(num != 0){
		oct = num % 8;
		num = num / 8;
		arr[i++] = '0' + oct;
	}
	for(j = 0; j < i; j++){
		final[j] = arr[i - j - 1];
	}
	final[j] = '\0';
}

void conDecHex(int num, char *final){
	int i = 0, hex, j;
	char arr[32];
	while(num != 0){
		hex = num % 8;
		num = num / 8;
		arr[i++] = '0' + hex;
	}
	for(j = 0; j < i; j++){
		final[j] = arr[i - j - 1];
	}
	final[j] = '\0';
}

int askQues(){
		
	int conv1, conv2, dec;
		
	printf("This program converts number systems\n\n");
	printf("Which number system would you like to convert FROM? (1) Decimal, (2) Binary, (3) Octal, (4) Hexadecimal: ");
	scanf("%d", &conv1);
	
	printf("Which number system would you like to convert TO?");
	switch(conv1){
		case 1:
			printf(" (5) Binary, (7) Octal, (8) Hexadecimal: ");
			break;
		case 2: 
			printf(" (6) Decimal, (7) Octal, (8) Hexadecimal: ");
			break;
		case 3: 
			printf(" (6) Decimal, (7) Binary, (8) Hexadecimal: ");
			break;
		case 4: 
			printf(" (5) Decimal, (6) Binary, (7) Octal: ");
			break;
		default: 
			printf("Invalid choice");
			return 1;
			break;
	}
	scanf("%d", &conv2);
	dec = conv1 + conv2;
	if(dec < 6){ printf("Invalid input"); exit(0);}
	return dec;
}
