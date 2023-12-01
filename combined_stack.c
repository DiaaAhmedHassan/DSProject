#include<stdio.h>
#include<stdlib.h> // for malloc & free

typedef struct
{
    int *collection;
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

    s->collection = malloc(sizeof(int) * capacity);
    
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
    // mohab
}


int isFull(stack *s)
{
    // mahmoud
}

int isEmpty(stack *s)
{
    // mohab
}

int push(stack *s, int item) // return true if the item is successfully pushed !
{
    // diaa
}

int pop(stack *s, int* item)
{
    //youssef
    if(s->top == -1)
    {
        s->underflow = 1;
        return(0);
    }
    s->top = s->top - 1;
    return 1;
}

int peak(stack *s, int *item) // return via "pass by pointer", the item at the top of the stack
{
    //mahmoud
}

int getStackSize(stack *s)
{
    // youssef
    return(s->top - 1);
}

int main()
{
    // stack creation
    stack *s = newStack(5);

    // testing here

    // freeing memory
    destroyStack(s);   
}