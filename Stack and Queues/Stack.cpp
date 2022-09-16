#include<iostream>
#include<stdio.h>
using namespace std;

struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *STACK=NULL;

void createStack(int cap)
{
    STACK =(struct ArrayStack*)malloc(sizeof(ArrayStack));
    STACK->capacity=cap;
    STACK->top=-1;
    
    //Creating array of size = capacity
    STACK->array=(int*)malloc(sizeof(int)*cap);
    
} 

int isEmpty()
{
    if(STACK->top==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(STACK->top==STACK->capacity-1)
        return 1;
    else
        return 0;
}

void push(int data)
{

    if(!isFull())
    {
        STACK->top += 1;
        STACK->array[STACK->top]=data;
    }
    else
        cout<<"\n STACK is fulll.";
}

void pop()
{
    int item;
    if(!isEmpty())
    {
        item = STACK->array[STACK->top];
        STACK->top-=1;
        cout<<"Poped Element is: "<<item;
        
    }
    else
        cout<<"\n STACK is empty.";

}

int main()
{
    int size;
    cout<<"Jai Shri Krishana\n";
    cout<<"Enter the size of STACK: ";
    cin>>size;
    createStack(size);

    cout<<"\nSelect the Operation: ";
    cout<<"\n1. Push\n2. Pop\n3. Is Empty:\n4. Is Full\n5. exit";

    while (1)
    {
        cout<<"\nEnter your CHOICE: ";
        cin>>size;

        switch (size)
        {
        case 1:
        {   cout<<"Enter the element in STACK: ";
            cin>>size;
            push(size);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            size=isEmpty();
            if(size==1)
                cout<<"\nSTACK is empty.";
            else
                cout<<"\nSTACK is not empty.";
            break;
        }
        case 4:
        {
            size=isFull();
            if(size==1)
                cout<<"\nSTACK is Full.";
            else
                cout<<"\nSTACK is NOT Full.";
            break;
        }   
        case 5:
        {
            exit(0);
            break;
        }
        default:
        {
            cout<<"\nEnter a valid choice.";
            break;
        }
        }    
    }
    

    return 0;
}
