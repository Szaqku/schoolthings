#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Element{
	int value;
	struct Element *prev;
};

struct Element *top = NULL;
struct Element *bottom = NULL;

void put(int v){
	struct Element *element = malloc(sizeof(struct Element));
	element->value = v;
	if(top == NULL && bottom == NULL){
		top = element;
		bottom = element;
		printf("Dodano %d. \n",element->value);
		return;
	}	
	bottom->prev = element;
	element->prev = NULL;
	bottom = element;
	printf("Dodano %d. \n",element->value);
}

int get(){
	if(top == NULL || bottom == NULL){
		bottom = NULL;
		printf("Error. Brak elementow.");
		return -1;
	}
	struct Element *now = top;
	if(now->prev == NULL)
		bottom = NULL;
	top = now->prev;
	int val = now->value;
	free(now);
	printf("Zdejmuje %d.\n",val);
	return val;
}



int main(int argc, char *argv[]) {
	
	int sterownik = 0;
	int d = 0;
	while(1){
		printf("Mozliwosci programu to: \n| 1 push \n| 2 pop \n| else END \n");
		scanf("%d",&sterownik);
		switch(sterownik){
			case 1:
				printf("Podaj liczbe: ");
				scanf("%d",&d);
				printf("\n");
				put(d);
				break;
			case 2: 
				get();
				break;
			default: 
				return 0;
		}
		//printf("TOP: %d\n",top->value);
		//printf("BOT: %d\n",bottom->value);
		printf("\n");
	}
	
	
	return 0;
}


