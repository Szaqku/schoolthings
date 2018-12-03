#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

	void readDataToMatrix(int **M, int m, int n);
	int mnozenie(int **A,int **B, int i,int j, int n);
	void matrixFree(int **M,int m);
	int **createMatrix(int m, int n);
	void printMatrix(int **M,int m,int n);
	int **mnozenieMacierzy(int **A, int**B, int i, int j, int n);
	int **readFromFile(char* filename,int *m,int* n, int* k,int **A,int **B);
	int** writeResultsToFile(char *filename,int **M, int m, int n);

int main(int argc, char *argv[]) {

	int m,n,k;
	FILE *f = fopen("we.txt","r");
	if(f == NULL){
		printf("NIE");
		printf("\n%s", strerror(errno));
		return 0;
	}
	
		fscanf(f,"%d",&m);
		printf("%d\n",m);
		fscanf(f,"%d",&n);
		printf("%d\n",n);
		fscanf(f,"%d",&k);
		printf("%d\n",k);
		
		int buff;
		int **A = createMatrix(m,n);
		int **B = createMatrix(n,k);
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				fscanf(f,"%d",(*(A+i)+j));
				printf("%d\n",*(*(A+i)+j));
			}
		}
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < k; j++){
				fscanf(f,"%d",(*(B+i)+j));
			}
		}
		
		fclose(f);
		
		printMatrix(A,m,n);
		printf("\n");
		printMatrix(B,n,k);
		printf("\n");
		
		int **C = mnozenieMacierzy(A,B,m,n,k);
//		
		printMatrix(C,m,k);
//		
		writeResultsToFile("wy.txt",C,m,k);
		
		//return C;
	 
	return 0;
}

	/*int **readFromFile(char* filename,int *m,int* n, int* k,int **A,int **B){
		FILE *f = fopen(filename,"r");
		scanf(f,"%d",m);
		scanf(f,"%d",n);
		scanf(f,"%d",k);
		
		int buff;
		A = createMatrix(*m,*n);
		B = createMatrix(*n,*k);
		
		for(int i = 0; i < *m; i++){
			for(int j = 0; j < *n; j++){
				scanf(f,"%d",A[i][j]);
			}
		}
		
		for(int i = 0; i < *m; i++){
			for(int j = 0; j < *k; j++){
				scanf(f,"%d",B[i][j]);
			}
		}
		
		fclose(f);
		
		printMatrix(A,*m,*n);
		printf("\n");
		printMatrix(B,*n,*k);
		printf("\n");
		
		int **C = mnozenieMacierzy(A,B,*m,*n,*k);
//		
//		printMatrix(C,*m,*k);
//		
//		writeResultsToFile("wy.txt",C,*m,*k);
		
		return C;
	}
	*/
	int** writeResultsToFile(char *filename,int **M, int m, int n){
		FILE *f = fopen(filename,"w");
		fprintf(f,"%d\n%d\n",m,n);
		for(int i = 0; i < n; i++){
			for(int j = 0 ; j < m;j++){
				fprintf(f,"%d\n",M[i][j]);
			}
		}
		fclose(f);
	}
	
	void readDataToMatrix(int **M, int m, int n){
		int v1 = 0;
		int v2 = 0;
		for(;v1 < m; v1++){
			v2 = 0;
			for(;v2 < n; v2++){
		 		scanf("%d",(*(M+v1)+v2));
			}
		}
	}
	
	int **mnozenieMacierzy(int **A, int**B, int m, int n, int k){
		int **C = createMatrix(m,n);
		int i = 0;
		int j = 0;
		for(;i < m;i++){
			j = 0;
			for(;j < k;j++){
		 		*(*(C+i)+j) = mnozenie(A,B,i,j,n);	
			}
		}
		return C;
	}

	void printMatrix(int **M,int m,int n){
		int i = 0;
		int j = 0;
		for(;i < m;i++){
			int j = 0;
			for(;j < n;j++){
		 		printf("%3d ",*(*(M+i)+j));
			}
			printf("\n");
		}
	}

	int mnozenie(int **A,int **B, int i,int j, int n){
		int wynik = 0;
		int h = 0;
		for(;h<n;h++){
			wynik += (*(*(A+i)+h)) * (*(*(B+h)+j));
		}
		return wynik;
	}
	
	void matrixFree(int **M,int m){
		int i = 0;
		for(;i<m;i++){
			free(*(M+i));
		}
		free(M);
	}
	
	int **createMatrix(int m, int n){
		int **M = malloc(m*sizeof(int));
		int i;
		for(i = 0 ; i < n; i++){
			*(M+i) = malloc(n*sizeof(int));	
		}
		return M;
	}

