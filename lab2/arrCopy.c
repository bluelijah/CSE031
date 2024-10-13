#include <stdio.h>
#include <stdlib.h> //Include for malloc and free
#include <string.h>

int size; // Variable to record size of original array arr
int evenCount = 0, oddCount = 0; // Variables to record sizes of new arrays arr_even and arr_odd
int *arr; // Dynamically allocated original array with #elements = size
int *arr_even;  // Dynamically allocated array with #elements = #even elements in arr (evenCount)
int *arr_odd;   // Dynamically allocated array with #elements = #odd elements in arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";

/*
 * DO NOT change the definition of the printArr function when it comes to 
 * adding/removing/modifying the function parameters, or changing its return 
 * type. 
 */
void printArr(int *a, int size, char *prompt){
	// Your code here
    printf("%s ", prompt);
    if(size == 0){
       printf("empty"); 
    }
    for(int i = 0; i < size; i++){
        printf("%d ", *(a + i));
    }
    printf("\n");
}

/* 
 * DO NOT change the definition of the arrCopy function when it comes to 
 * adding/removing/modifying the function parameters, or changing its return 
 * type. 
 */
void arrCopy(){ //prints the contents of the array
    int k = -1;
    int a = -1; 
    for(int i = 0; i < size; i++){ //creates loop that iterates through the indeces of the array using two counters, k and a
        if(*(arr + i) % 2 == 0){ //Use dereferencing instead of []
            k++;
            *(arr_even + k) = *(arr + i); //Copy evens
        } else {
            a++;
            *(arr_odd + a) = *(arr + i); //Copy odds
        }
    }
}

int main(){
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &size); //for size of the array
    arr = (int*)malloc(size * sizeof(int)); //allocates memory for the array based on size() of array
    int num;
    for(int i = 0; i < size; i++){ //reads each element of the array, updating even counter or odd counter depending on the element
        printf("Enter array element #%d: ", i+1);
        scanf("%d", &num); //creates temporary holder for value, then assigns the value, and resets to next value afterwards
        *(arr + i) = num;
        if(num % 2 == 0){
            evenCount++;
        }
        else if( num % 2 != 0){
            oddCount++;
        }
    }
    printf("\n");
    arr_even = (int*) malloc(evenCount * sizeof(int)); //allocates memory for even array
    arr_odd = (int*) malloc(oddCount * sizeof(int)); //allocates memory for odd array

    // Dynamically allocate memory for arr (of appropriate size)
    // Your code here

    // Ask user to input content of arr and compute evenCount and oddCount
	// Your code here

    // Dynamically allocate memory for arr_even and arr_odd (of appropriate size)
    // Your code here    
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	// Print original array
    printArr(arr, size, str1);

	/// Copy even elements of arr into arr_even and odd elements into arr_odd
    arrCopy();

    // Print new array containing even elements from arr
    printArr(arr_even, evenCount, str2);

    // Print new array containing odd elements from arr
    printArr(arr_odd, oddCount, str3);

    printf("\n");

    return 0;
}