#include <stdio.h>
#include <stdlib.h> // for malloc, free and atoi


typedef struct node
{
    int data;
    struct node *next;
}
node;


int main(int argc, char *argv[])
{
    node *list = NULL;

    for(int i = 1; i < argc; i++)
    {
        //parsing the input
        int number = atoi(argv[i]);
        // using atoi, assuming the user will always input an integer

        //node creation
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            printf("allocation failed");
            return(-1);
        }
        n->data = number;
        n->next = NULL;

        // prepending to the list, sequence of operations matters !
        n->next = list;
        list = n;
    }

    // printing the data in the list
    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");


    // cleaning before termination
    ptr = list;
    while(ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return(0);
}