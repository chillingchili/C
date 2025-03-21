#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void insertData(struct node** a, int x){
	struct node** ptr;
	for(ptr = a; *ptr != NULL; ptr = &(*ptr)->next){}
	*ptr = malloc(sizeof(struct node));
	if(*ptr != NULL){
		(*ptr)->data = x;
		(*ptr)->next = NULL;
	}
}

void displayList(struct node* a){
	struct node* temp = a;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void swapElem(struct node** a, int x, int y){
	struct node *prevA = NULL, *currA, *prevB = NULL, *currB;
	for(currA = *a; currA != NULL && currA->data != x; prevA = currA, currA = currA->next){}
	for(currB = *a; currB != NULL && currB->data != y; prevB = currB, currB = currB->next){}


	if(currA == NULL || currB == NULL) return;
	
	if(prevA != NULL){
		prevA->next = currB;
	} else {
		*a = currB;
	}
	
	if(prevB != NULL){
		prevB->next = currA;
	} else {
		*a = currA;
	}
	
	struct node* temp = currA->next;
	currA->next = currB->next;
	currB->next = temp;

//	if(prevB == currA && prevA == NULL){
//		next = currB->next;
//		*a = currB;
//		(*a)->next = currA;
//		currA->next = next;
//	} else if(prevB == currA){
//		next = currA->next;
//		currA->next = next->next;
//		next->next = currA;
//		if(prevA != NULL) prevA->next = next;
//	} else if(prevA == NULL) {
//		next = currA->next;
//		*a = currB;
//		currA->next = currB->next;
//		(*a)->next = next;
//		next->next = currA;
//	} else {
//		next = currA->next;
//		currA->next = currB->next;
//		prevA->next = currB;
//		currB->next = next;
//		prevB->next = currA;
//	}	
}

int main(){
	struct node* a = NULL;
	insertData(&a, 1);
	insertData(&a, 2);
	insertData(&a, 3);
	insertData(&a, 4);
	
	printf("Linked list: ");
	displayList(a);
	
	int x, y;
	printf("Enter two values to swap (x) (y): ");
	scanf("%d %d", &x, &y);
	
	swapElem(&a, x, y);
	displayList(a);
	return 0;
}
