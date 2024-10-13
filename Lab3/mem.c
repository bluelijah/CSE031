#include <stdio.h>
#include <stdlib.h>

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *) malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **) malloc(1 * sizeof(int *));
	*handle = ptr;

	// Insert code here
	printf("Address of num: %p\n", (void *)&num);
	printf("Address of ptr: %p\n", (void *)&ptr);
	printf("Address of *ptr: %p\n", (void *)ptr);
	printf("Address of handle: %p\n", (void *)&handle);
	printf("Address of *handle: %p\n", (void *)handle);

	return 0;
} 

