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
    free(s->collection);
    free(s);
}

int isEmpty(stack *s)
{
    return(s->top == -1);
}

int isFull(stack *s)
{
    return(s->top == s->capacity - 1);
}

int push(stack *s, int item) // return true if the item is successfully pushed !
{
    if(isFull(s))
    {
        s->overflow = 1;
        return 0;
    }

    s->top += 1;
    s->collection[s->top] = item;
    return(1);
}

int pop(stack *s)
{
    if(isEmpty(s))
    {
        s->underflow = 1;
        return 0;
    }

    s->top -= 1;
}

int peak(stack *s, int *item) // return via "pass by pointer", the item at the top of the stack
{
    *item = s->collection[s->top];
}

int getStackSize(stack *s)
{
    return(s->top + 1);
}

int main()
{
    stack *s = newStack(5);

    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);

    printf("the stack size is: %d\n", getStackSize(s));
    printf("is the stack full? %i\n", isFull(s));
}