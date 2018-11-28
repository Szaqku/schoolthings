#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
//	int A[100][100];
//	int B[100][100];
//	int C[100][100];
	 
//	int A[3][3] = {{1,1,1},{3,1,4},{5,6,1}};
//	int B[3][3] = {{2,1,3},{5,2,2},{6,4,1}};
//	int C[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
	// 1 1 1 3 1 4 5 6 1 
	// 2 1 3 5 2 2 6 4 1 
	// 3 3 3 1 1 1 3 1 4 5 6 1 2 1 3 5 2 2 6 4 1
	int m,n,k;
	 
	printf("Podaj m,n,k: w formacie: m n k\n");
	scanf("%d %d %d",&m,&n,&k); 
	 
	int i = 0;
	int **A = malloc(m*sizeof(int));
	for(;i<m;i++){
		*(A+i) = malloc(n*sizeof(int));
	}
	i = 0;
	int **B = malloc(n*sizeof(int));
	for(;i<n;i++){
		*(B+i) = malloc(k*sizeof(int));
	}
	i = 0;
	int **C = malloc(m*sizeof(int));
	for(;i<m;i++){
		*(C+i) = malloc(k*sizeof(int));
	}
//	 int **B = createMatrix(n,k);
//	 int **C = createMatrix(m,k); 
	 
	 int v1 = 0;
	 int v2 = 0;
	 for(;v1 < m; v1++){
	 	v2 = 0;
	 	for(;v2 < n; v2++){
	 		scanf("%d",(*(A+v1)+v2));
		 }
	 }
	 v1 = 0;
	 v2 = 0;
	 for(;v1 < n; v1++){
	 	v2 = 0;
	 	for(;v2 < k; v2++){
	 		scanf("%d",(*(B+v1)+v2));
		 }
	 } 
	 
	i = 0;
	int j = 0;
	for(;i < m;i++){
		j = 0;
		for(;j < k;j++){
	 		*(*(C+i)+j) = mnozenie(A,B,i,j,n);	
		}
	}
	
	printf("\n\nWynik:\n");
	
	i = 0;
	j = 0;
	for(;i < m;i++){
		int j = 0;
		for(;j < n;j++){
	 		printf("%3d ",*(*(A+i)+j));
		}
		printf("\n");
	}
	printf("\n");
	i = 0;
	j = 0;
	for(;i < n;i++){
		int j = 0;
		for(;j < k;j++){
	 		printf("%3d ",*(*(B+i)+j));
		}
		printf("\n");
	}
	printf("\n");
    i = 0;
	j = 0;
	for(;i < m;i++){
		int j = 0;
		for(;j < k;j++){
	 		printf("%3d ",*(*(C+i)+j));
		}
		printf("\n");
	}
	 
	 	for(;i<m;i++){
			free(*(A+i));
		}
		free(A);
	 
		 for(;i<n;i++){
			free(*(B+i));
		}
		free(B);
		
		for(;i<m;i++){
			free(*(C+i));
		}
		free(C);
	
	 
	return 0;
	
	
}

	int mnozenie(int **A,int **B, int i,int j, int n){
		int wynik = 0;
		int h = 0;
		for(;h<n;h++){
			wynik += (*(*(A+i)+h)) * (*(*(A+h)+j));
		}
		return wynik;
	}
	
	void matrixFree(int** M,int m){
		int i = 0;
		for(;i<m;i++){
			free(*(M+i));
		}
		free(M);
	}
