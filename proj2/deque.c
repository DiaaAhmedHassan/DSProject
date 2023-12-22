#include <stdio.h>
#include <stdlib.h> // for malloc and free

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
        return(NULL);
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

int isEmpty(Deque *d)// Diaa
{
    return(d->size == 0);
}

void insertFront(Deque *d, int value) // Youssef
{
    // creation of a new node
    node *n = malloc(sizeof(node));
    n->data = value;
    n->next = NULL;
    n->prev = NULL;

    // linking the new node
    if(isEmpty(d))
    {
        d->front = n;
        d->rear = n;
    }
    else
    {
        n->next = d->front;
        d->front->prev = n;
        d->front = n;
    }
    d->size++;
}

void insertRear(Deque *d, int value) // Youssef
{
    // creation of a new node
    node *n = malloc(sizeof(node));
    n->data = value;
    n->next = NULL;
    n->prev = NULL;

    // linking the new node
    if(isEmpty(d))
    {
        d->front = n;
        d->rear = n;
    }
    else
    {
        d->rear->next = n;
        n->prev = d->rear;
        d->rear = n;
    }
    d->size++;
}

int removeFront(Deque *d) //Diaa
{
    //check the underflow condition
    if(isEmpty(d))
    {
        printf("%s", "underflow error");
        return(-1);
    }

    //store current front in a tem variable
    int val = d->front->data;
    node *oldFront = d->front;

    //check if the deque has only one element
    if (d->size == 1)
    {
        d->front = NULL;
        d->rear = NULL;
        free(oldFront);
    }
    else
    {
        //update the front to point to the next node
        d->front = d->front->next;
        free(oldFront);
        d->front->prev = NULL;
    }
    d->size--;
    return val; 
}

int removeRear(Deque *d){ //Diaa

    if(isEmpty(d))
    {
        printf("Under flow error");
        return(-1);
    }
    int val = d->rear->data;
    node *oldRear = d->rear;

    if(d->size == 1)
    {
        d->front = NULL;
        d->rear = NULL;
        free(oldRear);
    }
    else
    {
        d->rear = d->rear->prev;
        free(oldRear);
        d->rear->next = NULL;
    }
    d->size--;

    return val;
}

int size(Deque *d) // Diaa
{
    return(d->size);
}


int getFirstPosition(Deque *d, int value) // Mahmoud Reda
{
    if(isEmpty(d)){
        return -1;
    }
    int pos=1;
    node *current=d->front;

    while(current!=NULL){
        if(current->data==value){
            return pos;
        }
        current=current->next;
        pos++;
    }
    return -1;

}
int getLastPosition(Deque *d, int value) // Mahmoud Reda
{
    if(isEmpty(d)){
        return -1;
    }
    int pos=d->size;
    node *current=d->rear;

    while(current!=NULL){
        if(current->data==value){
            return pos;
        }
        current=current->prev;
        pos--;
    }
    return -1;
}
int getCount(Deque *d, int value) // Mahmoud Reda
{
    int count = 0;
    node *current=d->front;

    while (current!=NULL){
        if(current->data==value){
            count++;
        }
        current=current->next;
    }
    return count;
}

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

int getKth(Deque *d, int k)// Diaa
{
    if (isEmpty(d) || k < 0)
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

int linearSearch(Deque *d, int value) // Mohab
{
    node *ptr = d->rear;
    int position = d->size;
    while(ptr != NULL)
    {        
        if(ptr->data == value)
        {
            return(position);
        }
        position--; 
        ptr = ptr->prev;
    }
    return(-1);
}

void printForwards(Deque *d) // Mahmoud and Mohab
{
    node *ptr = d->front;

    while (ptr!=NULL){
        printf("%d", ptr->data);
        ptr=ptr->next;
    }

    printf("\n");
}
void printBackwards(Deque *d) // Mahmoud and Mohab
{
    node *ptr = d->rear;
    while (ptr!=NULL)
    {
        printf("%d", ptr->data);
        ptr=ptr->prev;
    }

    printf("\n");
}
void deleteKth(Deque *d, int k) // Mahmoud and Mohab
{
    if(isEmpty(d) || k < 0||k > d-> size){
        return;
    }
    if(k==1){
        removeFront(d);
    }
    else if(k==d->size){
        removeRear(d);
    }
    else{
        node *current=d->front;
        int count=1;

        while(count<k&&current!=NULL) {
            current=current->next;
            count++;
        }
        if(current!=NULL) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        d->size--;
    }
    }
}


int main()
{
    //code here
    Deque *d = create();
    insertRear(d, 5);
    insertRear(d, 6);
    insertRear(d, 7);

    node *ptr = d->front;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n"); // 5 6 7

    insertFront(d, 9);
    insertFront(d, 10);
    insertFront(d, 11);
    insertFront(d, 12);
    ptr = d->front;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n"); // 12 11 10 9 5 6 7


    removeFront(d);
    removeFront(d);
    ptr = d->front;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n"); // 10 9 5 6 7

    removeRear(d);
    removeRear(d);
        ptr = d->front;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    insertRear(d, 10);

    printf("min: %d\n" ,getMin(d));
    printf("max: %d\n" ,getMax(d));

    printf("getFirstPosition: %d\n" , getFirstPosition(d,10));
    printf("getLastPosition: %d\n" , getLastPosition(d,10));
    printf("getCount: %d\n" , getCount(d,9));

    printf("position: %i\n" ,linearSearch(d, 7));

    printBackwards(d);
    printForwards(d);
    deleteKth(d,2);
    printForwards(d);

    return(0);
}