#include <stdio.h>
#include <stdlib.h> // for malloc and free

typedef struct node
{
    int data;
    struct node *next;
}
node;

typedef struct 
{
    node *front;
    node *rear;
    int size;
}
Dequeue;

Dequeue* create()
{
    Dequeue *d = malloc(sizeof(Dequeue));
    if(d == NULL)
    {
        printf("allocation error\n");
        return(-1);
    }

    d->front = NULL;
    d->rear = NULL;
    d->size = 0;

    return(d);
}

void insertFront(int value);
void insertRear(int value);
int removeFront();
int removeRear();
int size();
int isEmpty();
int getFirstPosition(int value);
int getLastPosition(int value);
int getCount();
int getMin();
int getMax();
int getKth(int k);
int linearSearch(int value);
void printForwards();
void printBackwards();
void deleteKth(int k);

int main()
{
    //code here
    return(0);
}