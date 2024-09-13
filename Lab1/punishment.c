#include <stdio.h>
int main(){
    int numOfTimes;

    printf("How many times shall I write my punishment: ");
    scanf("%d", &numOfTimes);

    for(int i = 0; i < numOfTimes + 1; i++){
        printf("Coding with C is awesome!\n") ;
    }

    return 0;
}