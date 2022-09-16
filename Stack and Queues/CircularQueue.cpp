#include<iostream>
#include<stdio.h>
using namespace std;

struct ArrayQueue
{
    int front=-1,rear;
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
    //we can also use following condition: (rear+1)%capacity==front 
    //if((Q->rear+1)%Q->capacity==Q->front)

    if((Q->rear==Q->capacity-1 && Q->front==0) || (Q->rear==Q->front-1))
        return 1;
    return 0;
}

int isQueueEmpty()
{
    if(Q->front==-1 )
        return 1;
    return 0;
}

void enQueue(int data)
{
    if(isQueueFull())
        cout<<"\nOverFlow :: Queue is Full.";
    else
    {
        Q->rear+=1;
        Q->array[Q->rear]=data;
        if(Q->front==-1)
            Q->front=0;
    }

}

int deQueue()
{
    int data=-1;
    if(isQueueEmpty())
        cout<<"\nUnderFlow :: Queue is Empty.";
    else
    {
        data=Q->array[Q->front];
        if(Q->front==Q->rear)
            Q->front=Q->rear=-1;
        else    
            Q->front=(Q->front+1) % Q->capacity;

        return data;    
       
    }

    return data;
}

int QueueSize()
{

    return (Q->capacity - Q->front + Q->rear + 1 ) % Q->capacity;

}

void deleteQueue()
{
    if(Q)
    {
        if(Q->array)
            free(Q->array);
        
        free(Q);
    }
}
int main(int argc, char const *argv[])
{
    int size;
    cout<<"Jai Shri Krishna\n";

    cout<<"Enter the size of Queue: ";
    cin>>size;
    createQueue(size);
    cout<<"1. Insertion\n2. Deletion\n3. Is Empty\n4. Is Full\n5. Size\n6. Delete\n7. exit\n";
    
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
            size=deQueue();
            if(size!=-1)
                cout<<"\nDeleated data is "<<size;
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
            cout<<"\nSize of Queue is "<<QueueSize();
            break;
        }case 6:
        {   
            deleteQueue();
            cout<<"Queue is deleted.";
            break;
        } 
        case 7:
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

