#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} nodeType, *list;

void insertData(list* a, int x){
	list* ptr;
	for(ptr = a; *ptr != NULL; ptr = &(*ptr)->next){}
	*ptr = malloc(sizeof(nodeType));
	if(*ptr != NULL){
		(*ptr)->data = x;
		(*ptr)->next = NULL;
	}
}

void displayList(list a){
	list temp;
	for(temp = a; temp != NULL; temp = temp->next){
		printf("%d ", temp->data);
	}
	printf("\n");
}

list combineLists(list a, list b){
	nodeType dummy;
	list temp = &dummy;
	while(a != NULL && b != NULL){
		if(a->data == b->data) {
			a = a->next;
			continue;
		} else if(a->data > b->data){
			temp->next = b;
			b = b->next;
		} else {
			temp->next = a;
			a = a->next;
		}
		temp = temp->next;
	}
	if(a == NULL){
		temp->next = b;
	} else {
		temp->next = a;
	}
	return dummy.next;
}

int main(){
	list x = NULL, y = NULL;
	insertData(&x, 1);
	insertData(&x, 2);
	insertData(&x, 3);
	insertData(&y, 3);
	insertData(&y, 4);
	insertData(&y, 5);
	displayList(x);
	displayList(y);
	
	list c = combineLists(x, y);
	displayList(c);
	return 0;
}
