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
Deque;

Deque* create() // Youssef
{
    Deque *d = malloc(sizeof(Deque));
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

void destroy(Deque *d) //Youssef
{
    node *ptr = d->front;
    while(ptr != NULL)
    {
        node *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }

    free(d);
}

void insertFront(Deque *d, int value) // Youssef
{
    // creation of a new node
    node *n = malloc(sizeof(node));
    n->data = value;
    n->next = NULL;

    // linking the new node
    n->next = d->front;
    d->front = n;
    d->size++;
}

void insertRear(Deque *d, int value) // Youssef
{
    // creation of a new node
    node *n = malloc(sizeof(node));
    n->data = value;
    n->next = NULL;

    // linking the new node
    d->rear->next = n;
    d->rear = n;
    d->size++;
}
int removeFront(Deque *d)
{
    //hints:
    // check for underflow
    // if not proceed
    // make a tmp pointer of type node
    // store d->front->data in a variable called "value" for example
    // set tmp = d->front
    // make d->front point at the next node
    // free tmp
    //update d->size
    // return(value);
    
    return(0); // delete this
}
int removeRear();
int size();
int isEmpty();
int getFirstPosition(int value);
int getLastPosition(int value);
int getCount();

int getMin(Deque *d) // Youssef
{
    int mn = 999999;
    node *n = d->front;
    while(n != NULL)
    {
        if(n->data < mn)
        {
            mn = n->data;
        }
        n = n->next;
    }
    return(mn);
}

int getMax(Deque *d) // Youssef
{
    int mx = -999999;
    node *n = d->front;

    while(n != NULL)
    {
        if(n->data > mx)
        {
            mx = n->data;
        }
        n = n->next;
    }
    return(mx);
}

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