#include<iostream>
#include<stdio.h>
using namespace std;

//creating a structure for queue

struct ArrayQueue
{
    int front,rear;
    int capacity;
    int *array;
};

struct ArrayQueue *Q=NULL;

void createQueue(int cap)
{
    Q=(struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));
    Q->capacity=cap;
    Q->array=(int *)malloc(sizeof(int)*cap);
    Q->front=-1;
    Q->rear=-1;
    
}

int isQueueFull()
{
    if(Q->rear==Q->capacity-1)
        return 1;
    return 0;
}

int isQueueEmpty()
{
    if(Q->front==-1 || Q->front>Q->rear)
        return 1;
    return 0;
}

void enQueue(int data)
{
    if(isQueueFull())
    {
        cout<<"\nOverFlow:: Queue is Full.\n";
    }
    else
    {
        Q->rear+=1;
        Q->array[Q->rear]=data;
        if(Q->front == -1)
            Q->front+=1;
    }
}

void deQueue()
{
    int data;
    if(isQueueEmpty())
        printf("\nUnderFlow::Queue is Empty.\n");
    else
    {
        data=Q->array[Q->front];
        if(Q->front==Q->rear)
            Q->front=Q->rear=-1;
        else
            Q->front+=1;
        cout<<"\nDeleted data is: "<<data;
    }

}

int main()
{
    int size;
    cout<<"Jai Shri Krishna\n";

    cout<<"Enter the size of Queue: ";
    cin>>size;
    createQueue(size);
    cout<<"1. Insertion\n2. Deletion\n3. Is Empty\n4. Is Full\n5. exit\n";
    
    while(1)
    {
        cout<<"Enter your choice: ";
        cin>>size;

        switch (size)
        {
        case 1:
        {
            cout<<"Enter the data: ";
            cin>>size;
            enQueue(size);
            break;
        }
        case 2:
        {
            deQueue();
            break;
        }
        case 3:
        {
            isQueueEmpty()?cout<<"Queue is Empty.":cout<<"Queue is not Empty.";
            break;
        }
        case 4:
        {
            printf(isQueueFull()?"Queue is Full.":"Queue is not Full.");
            break;
        } 
        case 5:
        {   
            exit(0);
            break;
        }   
        default:
            {
                cout<<"Enter a valid Entry."<<endl;
            }
            
        }
    }

    return 0;
}