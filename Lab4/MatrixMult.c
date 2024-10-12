
#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. 
	// You will need to create a new matrix to store the product.
	int **multarr = (int**)malloc(size * sizeof(int*)); //allocate memory for the new matrix
	int sum = 0;
	for(int i = 0; i < size; i++){ //iterates over the matrix rows
		*(multarr + i) = (int *)malloc(size * sizeof(int)); //allocate memory for each row
		for(int j = 0; j < size; j++){ //iterates over the matrix columns 
			sum = 0;
			for(int k = 0; k < size; k++){ //does the actual matrix multiplication
				sum += (*(*(a + i) + k)) * (*(*(b + k) + j)); //takes element i, k of matrix a, and element k, j of matrix b, calculates the sum
			}
			*(*(multarr + i) + j) = sum; //this sum is then stored in the corresponding index of the new array

		}
	}
	return multarr;

}

void printArray(int **arr, int n) {
	// (2) Implement your printArray function here
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
}

int main() {
	int n = 5;
	int **matA, **matB, **matC;
	// (1) Define 2 (n x n) arrays (matrices). 
	matA = (int**)malloc(n * sizeof(int*)); //to define matrix A, and initialize it with i entries for each column, c1 being all 0, c2 being all 1...
	for(int i = 0; i < n; i++){
		*(matA + i) = (int*)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++){
			*(*(matA + i) + j) = i;
		}
	}
	matB = (int**)malloc(n * sizeof(int*)); //to define matrix B, and initialize it with i entries for each column, c1 being all 0, c2 being all 1...
	for(int i = 0; i < n; i++){
		*(matB + i) = (int *)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++){
			*(*(matB + i) + j) = j;
		}
	}

	// (3) Call printArray to print out the 2 arrays here.
	printf("Matrix A:\n");
    printArray(matA, n);
    
    printf("Matrix B:\n");
    printArray(matB, n);
	
	// (5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n); //calls the multiplication and sets the array matC equal to the made array in that function
	
	// (6) Call printArray to print out resulting array here.
	printArray(matC, n);

    return 0;
}