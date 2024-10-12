#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>

void printArray(int**, int);

int main() {
	int i = 0, j = 0, n = 5;
	int **arr = (int**)malloc(n * sizeof(int*)); //allocates memory for n pointers

	// (3) Add your code to complete allocating and initializing the 2-D array here. The content should be all 0.
	for(int i = 0; i < n; i++){ //iterates through each row of the array
		*(arr + i) = (int *)malloc(n * sizeof(int)); //allocates memory for n integers for each column
		for(int j = 0; j < n; j++){ //iterates through each column of the current row
			*(*(arr + i) + j) = 0; //initializes each index of the matrix to zero
		}
	}

    // This will print out your array
	printArray(arr, n);

    // (6) Add your code to make arr a diagonal matrix
    for(int i = 0; i < n; i++){ //iterates through each row
		for(int j = 0; j < n; j++){ //iterates through each column of each row
			if(i == j){ //checks if the current element is diagonal as j and i would be equal, diagonals have equal j and i indices
				*(*(arr + i) + j) = (i + 1); //sets diagonal to i+1
			}
		}
	}
	
	
	// (7) Call printArray to print array
    printArray(arr, n);
	return 0;
}

void printArray(int ** array, int size) {
    // (5) Implement your printArr here:
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			printf("%d ", *(*(array + i) + j));
		}
		printf("\n");
	}
}