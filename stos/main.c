#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Element{
	int value;
	struct Element *next;
	struct Element *prev;
};

struct Element *top = NULL;

void push(int v){
	struct Element *element = malloc(sizeof(struct Element));
	element->value = v;
	element->prev = top;
	element->next = NULL;
	
	printf("Dodano %d\n",element->value);
	
	top = element;
}

int pop(){
	if(top == NULL){
		printf("Brak elementow na stosie, ERROR\n");
		return 0;
	}
	struct Element *now = top->prev;
	if(now==NULL){
		printf("Brak elementow na stosie, ERROR\n");
		top = NULL;
		return 0;
	}
	int v = top->value;
	free(top);
	
	top = now;
	
	printf("Zdejmuje %d\n",v);
	
	return v; 
}

int peek(){
	if(top==NULL){
		printf("Brak elementow na stosie, ERROR\n");
		return 0;
	}
	
	printf("Peek: %d",top->value);
	return top->value;
}


int main(int argc, char *argv[]) {

	push(1);
	push(5);
	push(25);
	pop();
	peek();
	printf("\nTop value = %d\n",top->value);
	
	int sterownik = 0;
	int d;
	
	while(1){
		printf("Mozliwosci programu to: \n| 1 push \n| 2 pop \n| 3 peek\n| else END \n");
		scanf("%d",&sterownik);
		switch(sterownik){
			case 1:
				printf("Podaj liczbe: ");
				scanf("%d",&d);
				printf("\n");
				push(d);
				break;
			case 2: 
				pop();
				break;
			case 3:
				peek();
				break;
			default: 
				return 0;
		}
		printf("\n");
	}
	
	
	return 0;
}


