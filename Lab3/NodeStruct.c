#include <stdio.h>
#include <stdlib.h>

struct Node { //defines struct node
    int iValue;
    float fValue;
    struct Node *next; //a pointer to next node in linked lists, linking nodes
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node)); //dynamically allocates memory for a singular node, malloc returning a pointer to the memory which is cast to node and strored in "head"
    head->iValue = 5; //assigning values to the members of the node that head points to
    head->fValue = 3.14;
	
	// Insert code here
	printf("Value of head (address of the node): %p\n", (void *)head);
    printf("Address of head: %p\n", (void *)&head);
    printf("Address of iValue in head: %p, Value: %d\n", (void *)&head->iValue, head->iValue);
    printf("Address of fValue in head: %p, Value: %.2f\n", (void *)&head->fValue, head->fValue);
    printf("Address of next in head: %p, Value stored in next: %p\n", (void *)&head->next, (void *)head->next);

	
	return 0;
}