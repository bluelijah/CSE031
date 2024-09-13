#include <stdio.h>
int main(){
    int numOfTimes;
    int validInput;
    int typoLine;

    do{
        printf("Enter the repetition count for the punishment phrase: ");
        validInput = scanf("%d", &numOfTimes);
        
        while(getchar() != '\n');
        if (validInput != 1 || numOfTimes <= 0) {
            printf("You entered an invalid value for the repetition count! Please Re-");
            validInput = 0;     
        }

    } while (!validInput);

    do{
        printf("Enter the line where you want to insert the typo: ");
        validInput = scanf("%d", &typoLine);

        while(getchar() != '\n');
        if (validInput != 1 || typoLine < 1 || typoLine > numOfTimes) {
            printf("You entered an invalid value for the typo placement! Please Re-");
            validInput = 0;     
        }
    } while (!validInput);

    for(int i = 1; i <= numOfTimes; i++){
        if(i == typoLine){
            printf("Cading wiht is C avesone!\n");
        } else{
            printf("Coding with C is awesome!\n") ;
        }
    }
    
    return 0;
}