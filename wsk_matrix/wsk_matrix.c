#include <stdio.h>
#include <stdlib.h>

	void readDataToMatrix(int **M, int m, int n);
	int mnozenie(int **A,int **B, int i,int j, int n);
	void matrixFree(int **M,int m);
	int **createMatrix(int m, int n);
	void printMatrix(int **M,int m,int n);
	int** mnozenieMacierzy(int **A, int**B, int i, int j, int n);

int main(int argc, char *argv[]) {

	int m,n,k;
	int **C;
	
	printf("Podaj m,n,k: w formacie: m n k\n");
	scanf("%d %d %d",&m,&n,&k); 
	
	int **A = createMatrix(m,n);
	int **B = createMatrix(m,n);
	 
	readDataToMatrix(A,m,n);
	readDataToMatrix(B,n,k);
	 
	C = mnozenieMacierzy(A,B,m,n,k);
	
	printf("\n\nWynik:\n");
	
	printMatrix(A,m,n);
	printf("\n");
	printMatrix(B,n,k);
	printf("\n");
    printMatrix(C,m,k);
	 
	matrixFree(A,m);
	matrixFree(B,k);
	matrixFree(C,m);
	 
	return 0;
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
		for(int i = 0 ; i < n; i++){
			*(M+i) = malloc(n*sizeof(int));	
		}
		return M;
	}
