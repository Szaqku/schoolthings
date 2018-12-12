#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {

	FILE *f = fopen("we.txt","r");
	if(!f){
		printf("Nope");
		return 0;
	}
	
	
	int suma = 0;
	int last = 0;
	int k;
	while(fscanf(f,"%d",&last) == 1){
		suma+=last;
		printf("Dodano: %d\n",last);
		if( last == 0)
			break;
			
		if(last > 0){
			for(int i = 1; i < last;i++){
				fscanf(f,"%d",&k);
			}
		}else{
			rewind(f);
			for(int i = 0; i < suma;i++){
				fscanf(f,"%d",&k);
			}
		}	
		
	}
	
	printf("\n Suma: %d",suma);
	
	fclose(f);
}

