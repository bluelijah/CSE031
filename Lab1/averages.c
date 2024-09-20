#include <stdio.h>
int main(){

int userInput;
int validInput;
double total_even = 0.0, total_odd = 0.0;
int count_even = 0, count_odd = 0;
int index = 1;
int printCounter = 1;

while(1){
    if (printCounter == 1){
        printf("Enter the 1st value: ");
        scanf("%d", &userInput);
        printCounter ++;
    } else if(printCounter == 2){
        printf("Enter the 2nd value: ");
        scanf("%d", &userInput);
        printCounter ++;
    } else if(printCounter == 3){
        printf("Enter the 3rd value: ");
        scanf("%d", &userInput);
        printCounter ++;
    } else {
        printf("Enter the %dth value: ", index);
        scanf("%d", &userInput);
    }
    


    if (userInput == 0) {
        break;
    }

    int sum_of_digits = 0;
    int temp = userInput;

    while (temp != 0) {
            sum_of_digits += temp % 10; 
            temp /= 10;
        }

       
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
        printf("\nAverage of input values whose digits sum up to an even number: %.2f", avg_even);
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