#include <stdio.h>
int main(){

    //to compile gcc -o punishment punishment.c
    //to run ./punishment

    int numOfTimes;
    int validInput;
    int typoLine;

    do{
        if (validInput != 0){
            printf("Enter the repetition count for the punishment phrase: ");
        }
        validInput = scanf("%d", &numOfTimes);
        
        while(getchar() != '\n');
        if (validInput != 1 || numOfTimes <= 0) {
            printf("You entered an invalid value for the repetition count! Please re-enter: ");
            validInput = 0;     
        }

    } while (!validInput);

    printf("\n");

    do{
        if (validInput != 0) {
            printf("Enter the line where you want to insert the typo: ");
        }
        validInput = scanf("%d", &typoLine);

        while(getchar() != '\n');
        if (validInput != 1 || typoLine < 1 || typoLine > numOfTimes) {
            printf("You entered an invalid value for the typo placement! Please re-enter: ");
            validInput = 0;     
        } 
    } while (!validInput);

    printf("\n");

    for(int i = 1; i <= numOfTimes; i++){
        if(i == typoLine){
            printf("Cading wiht is C avesone!\n");
        } else{
            printf("Coding with C is awesome!\n") ;
        }
    }
    
    return 0;
}