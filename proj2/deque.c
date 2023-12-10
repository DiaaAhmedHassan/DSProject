#include <stdio.h>
#include <stdlib.h> // for malloc and free
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
int removeFront(Deque *d) //Diaa
{
    //check the underflow condition
  if(isEmpty(d)){
    printf("%s", "underflow error");
    return NULL;
  }

 //store current front in a tem variable
  int val = d->front->data;
  node *oldFront = d->front;

 //check if the deque has only one element
  if (d->size == 1)
  {
    d->front = NULL;
    d->rear = NULL;
  }else{
//update the front to point to the next node
  d->front = d->front->next;
  }
  free(oldFront);

  d->size--;
  
    
    return val; 
}
int removeRear(Deque *d){ //Diaa

    if(isEmpty(d)){
        printf("Under flow error");
        return NULL;
    }
    int val = d->rear->data;
    node *oldRare = d->rear;

    if(d->size == 1){
        d->front = NULL;
        d->rear = NULL;
    }else{
        d->rear = d->rear->next;
    }

    free(oldRare);

    d->size--;

    return val;
}
int size(Deque *d){ // Diaa
    return sizeof(d);
}
int isEmpty(Deque *d){//Diaa
    if (d->front == d->rear)
    {
        return true;
    }else{
        return false;
    }
    
    
};
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

int getKth(Deque *d, int k){ //Diaa
    if (isEmpty(d) || k <0)
    {
        return -1;
    }

    node *current = d->front;
    int count = 1;

    while (current != NULL && count<k)
    {
        current = current->next;
        count++;
    }

    if(current == NULL){
        return -1;
    }

    return current->data;    
}
int linearSearch(int value);
void printForwards();
void printBackwards();
void deleteKth(Deque *d, int k){

}

int main()
{
    //code here
    return(0);
}