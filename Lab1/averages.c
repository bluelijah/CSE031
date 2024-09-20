#include <stdio.h>
int main(){

//for each player input, add to a list, or vector, 
//then once 0 is entered, in a nested for loop, take the first value of the vector, and add it to the next
//then divide this by modulo to see if its even or odd. add to even or odd integer, then increase a counter for either even or odd sums
// once the nested loop has added all them together n!, solve for the average sums by dividing the int by its respective counter

int userInput;
int validInput;
double total_even = 0.0, total_odd = 0.0;
int count_even = 0, count_odd = 0;
int index = 1;

while(1){
    printf("Enter the %d value: ", index);
    scanf("%d", &userInput);

    if (userInput == 0) {
        break;
    }

    int sum_of_digits = 0;
    int temp = userInput;

    while (temp != 0) {
            sum_of_digits += temp % 10; // Add the last digit
            temp /= 10; // Remove the last digit
        }

        // Check if the sum of digits is even or odd
        if (sum_of_digits % 2 == 0) {
            total_even += userInput;
            count_even++;
        } else {
            total_odd += userInput;
            count_odd++;
        }

        index++;
    }
    if (count_even > 0) {
        double avg_even = total_even / count_even;
        printf("\nAverage of input values whose digits sum up to an even number: %.2f\n", avg_even);
    } else {
        printf("");
    }

    if (count_odd > 0) {
        double avg_odd = total_odd / count_odd;
        printf("\nAverage of input values whose digits sum up to an odd number: %.2f\n", avg_odd);
    } else {
        printf("");
    }

    if(count_even == 0 && count_odd == 0){
        printf("\nThere is no average to compute.");
    }

return 0;
}