#include <stdio.h>
int main() {
    int x = 5, y = 10, *px, *py;
    int arr[10];
    px = &x;
    py = &y;
    size_t len = sizeof(arr);
    int *arrptr = arr;

    for(int i = 0; i < len; i++){
        arr[i] = i+1;
        printf("%d\n", *arrptr + i);
    }

    printf("%d\n", *px);
    printf("%d\n", *py);
    printf("%p\n", (void*)px);
    printf("%p\n", (void*)py);
    printf("%p\n", (void*)&arr[0]);
    printf("%p\n", (void*)arr); 
    return 0;
}
