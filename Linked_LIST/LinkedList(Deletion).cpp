#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int id;
    struct node* next;

};
struct node* START=NULL;

struct node* createNode()
{
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}

void insertNode(int info)
{
    struct node* temp;
    temp=createNode();

    temp->next=NULL;
    temp->id=info;

    if(START==NULL)
    {
        START=temp;
    }
    else
    {
        struct node* a=START;

        while(a->next!=NULL)
        {
            a=a->next;
        }

        a->next=temp;
    }

}

void deleteNode(int info)
{
    struct node* temp=START,*p;
    int lock=0;

    if(START==NULL)
        cout<<"List Is Empty.";
    else
    if(START->id==info)
    {
        START=START->next;
        free(temp);
    }
    else
    {
        while(temp->id!=info)
        {
            p=temp;
            temp=temp->next;
            if(temp->id!=info && temp->next==NULL)
            {
                printf("\nEnter a Valid Entry.\n");
                lock=1;
                break;
            }
        }
            if(lock==0)
            {
                p->next=temp->next;
                free(temp);
            }
    }
    

}

void traverseLinkedList()
{
    struct node* a=START;

    cout<<"List Is: ";
    while(a!=NULL)
    {
        printf("%d -> ",a->id);
        a=a->next;
    }
    

}
int main()
{
    int data;
    cout<<"Jai Shri Krishna\n";
    cout<<"Enter the data:";
    cin>>data;
    insertNode(data);
    traverseLinkedList();
    cout<<"Enter the data:";
    cin>>data;
    insertNode(data);
    traverseLinkedList();
    cout<<"Enter the data:";
    cin>>data;
    insertNode(data);
    traverseLinkedList();
    cout<<"Enter the data:";
    cin>>data;
    insertNode(data);
    traverseLinkedList();

    cout<<"\nSelect data for deletion: ";
    cin>>data;
    deleteNode(data);
    traverseLinkedList();
    cout<<"\nSelect data for deletion: ";
    cin>>data;
    deleteNode(data);
    traverseLinkedList();
    cout<<"\nSelect data for deletion: ";
    cin>>data;
    deleteNode(data);
    traverseLinkedList();
    cout<<"\nSelect data for deletion: ";
    cin>>data;
    deleteNode(data);
    traverseLinkedList();
    

    cout<<"...............SIZE OF NODE:::::"<<endl<<sizeof(struct node);
    return 0;
}