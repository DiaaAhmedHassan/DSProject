#include<stdio.h>
#include<stdlib.h> // for malloc & free
#include<stdbool.h>

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
    
    stack *s = (stack*) malloc(sizeof(stack));
    if(s == NULL) return NULL; // in case of allocation errors

    s->collection = (char*) malloc(sizeof(char) * capacity);
    
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
    free(s->collection);
    free(s);
}


int isFull(stack *s)
{
    return ((s->top + 1) == s->capacity);
    // mahmoud
}

int isEmpty(stack *s)
{
    return(s->top == -1);
    // mohab
}

void push(stack *s, char item) // insert item into stack
{
    //diaa
    if(isFull(s)){
        s->overflow = 1;
        printf("\n overflow error \n");
    }else {
        s->top++;
        s->collection[s->top] = item;

    }
}

char pop(stack *s)
{
    //youssef
    if(s->top == -1)
    {
        s->underflow = 1;
        printf("\n underflow error \n");
        return '\0';
    }
    char popped = s->collection[s->top];
    s->top = s->top - 1;
    return popped;
}

int peak(stack *s)
{
    //mahmoud
    if (isEmpty(s)){
        printf("empty stack \n");
        return '\0';
    }

    return(s->collection[s->top]);
}

int getStackSize(stack *s)
{
    // youssef
    int size = s->top + 1;
    return(size);
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
        printf_s("%d%",pop(s));
    }
}

bool pair(char open, char close){
	if(open == '(' && close == ')')return true;
	else if(open == '{' && close == '}')return(1);
	else if(open == '[' && close == ']')return(1);
 	return(0);
}


int isbalanced (char str[], int size)
{
 	stack *open_brackets = newStack(size);
	
    for(int i = 0; i < size; i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            push(open_brackets, str[i]);
        }
	    else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(isEmpty(open_brackets))
            {
                return(0);
            }
		    else if(pair(peak(open_brackets), str[i]) == 0)
            {
                return(0);
            }

		    pop(open_brackets);
        }
    }
	   
    int ans = isEmpty(open_brackets);
    return(ans);
}

int main()
{
    // stack creation
    stack *s = newStack(5);

    // testing here
    // printf("is it empty ? %s \n", (isEmpty(s))? "yes": "no");

    // push(s, 'e');
    // printf("pushed a character, and it's the character %c \n", peak(s));

    // push(s, 'n');
    // printf("is it full ? %s \n", (isFull(s))? "yes": "no");
    
    // push(s, 'e');
    // push(s, 'm');
    // push(s, 'y');
    
    // printf("is it full ? %s \n", (isFull(s))? "yes": "no");
    
    // printf("stack size: %d\n", getStackSize(s));

    // printf("%c", pop(s));
    // printf("%c", pop(s));
    // printf("%c", pop(s));
    // printf("%c", pop(s));
    // printf("%c\n", pop(s));

    // printf("is it empty ? %s \n", (isEmpty(s))? "yes": "no");
    
    // problem 1 testing
    char str[] = "({[]]})";
    int size = sizeof(str) / sizeof(str[0]);

    printf("balanced? %s", (isbalanced(str, size)? "yes" : "no"));

    // freeing memory
    destroyStack(s);   
}