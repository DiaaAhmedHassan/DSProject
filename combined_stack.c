#include<stdio.h>
#include<stdlib.h> // for malloc & free

typedef struct
{
    char *collection;
    int capacity;
    int top;
    int underflow;
    int overflow;
}
stack;

stack* newStack(int capacity)
{
    //memory allocation
    if(capacity <= 0) return NULL;
    
    stack *s = malloc(sizeof(stack));
    if(s == NULL) return NULL; // in case of allocation errors

    s->collection = malloc(sizeof(char) * capacity);
    
    if(s->collection == NULL) // in case of allocation errors
    {
        free(s);
        return NULL;
    }

    // the rest of initialization steps
    s->capacity = capacity;
    s->top = -1;
    s->overflow = 0;
    s->underflow = 0;

    return(s);
}

void destroyStack(stack *s)
{
    free(s->collection);
    free(s);
    // mohab
}


int isFull(stack *s)
{
    // mahmoud
}

int isEmpty(stack *s)
{
    return(s->size==0);
    // mohab
}

int push(stack *s, char item) // return true if the item is successfully pushed !
{
    // diaa
}

char pop(stack *s)
{
    //youssef
    if(s->top == -1)
    {
        s->underflow = 1;
        return(NULL);
    }
    char popped = s->collection[s->top];
    s->top = s->top - 1;
    return popped;
}

int peak(stack *s, char *item) // return via "pass by pointer", the item at the top of the stack
{
    //mahmoud
}

int getStackSize(stack *s)
{
    // youssef
    return(s->top - 1);
}

// ------------ problems -------------
void str_invertion(char str[], int size)
{
    // int size = sizeof(str); // this will produce an error, the size has to passed as a parameter
    stack *s = newStack(size);

    for(int i = 0; i < size; i++)
    {
        push(s, str[i]);    
    }


    for(int i = 0; i < size; i++)
    {
        print(pop(s));
    }
}

int main()
{
    // stack creation
    stack *s = newStack(5);

    // testing here

    // freeing memory
    destroyStack(s);   
}