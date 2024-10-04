
#include <stdio.h>
#include <stdlib.h>

int* bubbleSort(int arr[], int n) { //takes an array and size n as inputs
    int temp, i = 0, j = 0; //temporary variable used for swapping elements
    int *s_arr = (int *) malloc(n * sizeof(int)); //dynamically allocated memory using malloc to store a sorted copy of the original array, allocating memory for n ints

    // // Copy arr to s_arr
    // for(i = 0; i < n; i++) //copies original array to s_arr
    //     s_arr[i] = arr[i];

    // // Sorting using array notations
	// // Comment this when implementing pointer version.
    // for (i = 0; i < n - 1; i++) { //for each element in the array, it comapres to next element, if larger swapping them
    //     for(j = 0; j < n - 1; j++) {
    //         if(s_arr[j] > s_arr[j + 1]) {
    //             temp = s_arr[j + 1];
    //             s_arr[j + 1] = s_arr[j];
    //             s_arr[j] = temp;
    //         }
    //     }
    // }

    // Sorting using pointer notations. i.e. you cannot use "[]"!
    // Your code goes here...

    for(i=0; i < n; i++){ //copying arr to s_arr using pointers instead
        *(s_arr + i) = *(arr + i); //a pointer to the ith index of the arr
    }

    for(i = 0; i < n - 1; i++){ //sort using pointer notation instead
        for(j = 0; j < n - 1; j++) {
            if(*(s_arr + j) > *(s_arr + j+1)){
                temp = *(s_arr + j+1);
                *(s_arr + j+1) = *(s_arr + j);
                *(s_arr + j) = temp;
            }
        }
    }
    return s_arr;
}

void printArray(int arr[], int n) { //just prints the array
    int i = 0;
    printf("[");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int bSearch(int *arr, int a, int b, int key) { //searched for a key in the sorted array between indicies a and b
    // Binary search function. arr is the array, key is the value to search for, a and b are the boundaries of arr to be searched within.
    // You must use pointer notations. i.e. no "[]"
    // Your code goes here:

    //sudo code
    //take n, the size of the algorithm, start in the middle, compare search value (&key) to n/2 +1 and n/2 - 1. 
    //If larger than n/2 +1, make another nested loop that deletes values of the array from 0 to n/2 + 1 index
    //if smaller than n/2 -1, make nested loop that deletes values of the array from n/2 -1, to n
    if (a > b){
        return -1; //changed to negative one becuase this would mean the function failed at finding the value
    }
    int arrSize = sizeof(arr);

    int mid = (a + b) / 2;
    if(*(arr + mid) == key){ //if the middle value is equal to the key
        return mid;
    } else if(*(arr + mid) < key) { //if the key is in the right half
        return bSearch(arr, mid + 1, b, key);
    } else { //if key is in the left half
        return bSearch(arr, a, mid -1, key);
    }
	//return 0; // Modify this to return an appropriate value!
}
    

int main() {

    int i = 0, size = 0, key = 0, result = 0;
    int *array, *sorted;

    printf("How big is your array?  ");
    scanf("%d", &size);
    array = (int *) malloc(size * sizeof(int));

    for(i = 0; i < size; i++) {
        printf("Please enter array[%d]:  ", i);
        scanf("%d", &array[i]);
    }

    printf("Please wait while I sort your numbers...\n");
    sorted = bubbleSort(array, size);
    printf("Here is your original array:\n");
    printArray(array, size);
    printf("Here is your SORTED array: \n");
    printArray(sorted, size);
    printf("What number are you looking for? ");
    scanf("%d", &key);
    printf("OK, let me see if I can find a \"%d\" in the array...\n", key);
    result = bSearch(sorted, 0, size-1, key);
    if(result != -1)
        printf("Got it! A \"%d\" is at index %d.\n", key, result);
    else
        printf("I'm sorry, a \"%d\" cannot be found in the array.\n", key);

	return 0;


}


