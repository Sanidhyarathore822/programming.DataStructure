#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int info;
    struct node* left,*right;  
};

struct node* START=NULL;

struct node* createNode()
{
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));

    return p;
}

void insertAtStart(int data)
{
    struct node* temp;

    temp=createNode();
    
    temp->info=data;
    temp->left=NULL;

    if(START==NULL)
    {   
        cout<<"\nJai Shri Krishna flag2\n";
        temp->right=NULL;             
        START=temp;
        cout<<temp->info;
    }
    else
    {
        cout<<"\nJai Shri Krishna flag1\n";
        temp->right=START;
        temp->right->left=temp;
        START=temp;
        //cout<<temp->info;
    }  
}
void insertAtLast(int data)
{
    struct node* temp;

    temp=createNode();
    temp->right=NULL;
    temp->info=data;

    if(START==NULL)
    {
        temp->left=START;
        START=temp;
    }
    else
    {
        struct node* a=START;
        while(a->right!=NULL)
        {
            a=a->right;
        }
        a->right=temp;
        temp->left=a;
    }    

    printf("::::::::Node INSERTED:::::::::\n");
}
void insertAfter(int data,int after)
{

    struct node* temp;
    int lock=0;
    temp=createNode();
    temp->info=data;
    if(START==NULL)
    {
        cout<<"\n:::::::::::Invalid INFORMATION::::::::::::::::";
    }
    else
    {
        struct node* a=START;
        while(a->info!=after)
        {
            if(a->right==NULL)
            {
                cout<<"\n:::::::::::Invalid INFORMATION::::::::::::::::";
                lock=1;
                break;
            }

            a=a->right;
        }
        if(lock!=1)
        {
            temp->right=a->right;
            temp->left=a;  

            if(a->right!=NULL)
                temp->right->left=temp;

            a->right=temp;

        }


    }

}
struct node* searchNode(int data)
{
    struct node* temp;
    int lock=0;
    int count=1;

    if(START==NULL)
    {
        cout<<"\nLINKED LIST is EMPTY.";
    }
    else
    {
        temp=START;
        while(temp->info!=data)
        {
            if(temp->right==NULL)
            {
                cout<<"\n:::::::::::Invalid INFORMATION::::::::::::::::";
                lock=1;
                temp=NULL;
                break;
            }
            temp=temp->right;
            count++;
        }
        if(lock!=1)
        {
            cout<<"Element Found at Node no. "<<count;
            cout<<endl<<"Address is: "<<temp;
        }
        
    }

    return temp;

}
void deleteAtStart()
{
    
    if(START==NULL)
    {
        cout<<"\nLinkedList is Empty.";
    } 
    else
    {
        struct node* temp=START;

        START=START->right;
        START->left=NULL;
        free(temp);
    }

}
void deleteAtLast()
{
    if(START==NULL)
    {
        cout<<"List Is Empty";
    }
    else
    {
        struct node* temp=START;
        if(START->right==NULL)
        {
            free(START);
            START=NULL;
        }
        else
        {
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->left->right=NULL;
            free(temp);
        }

    }
}
void deleteNode(int data)
{
    
    struct node* temp=searchNode(data);

    if(temp!=NULL)
    {
        if(temp->left==NULL)
        {
            START=temp->right;
            free(temp);
        }
        else
        if(temp->right==NULL)
        {
            temp->left->right=temp->right;
            free(temp);
        }
        else
        {
            temp->right->left=temp->left;
            temp->left->right=temp->right;   
            free(temp);         
        }
       
    }
    



}

void viewList()
{
    if(START==NULL)
        cout<<"\nList is Empty.";
    else
    {
        struct node* temp=START;

        while (temp!=NULL)
        {
            printf("|  %d  | ",temp->info);
            temp=temp->right;
        }
        
    }
    cout<<endl;
}



int main() n
{
    int data;
    cout<<"Jai Shri Krishna\n";
    
    insertAtStart(348);
    insertAtStart(34);
    insertAtLast(89);
    insertAtStart(3475);
    insertAfter(368,40);
    insertAfter(3,89);
    viewList();

    deleteAtLast();
    deleteAtStart();
    viewList();
    
    searchNode(89);
    viewList();

    deleteNode(66);
    viewList();




    //searchNode(66);
  return 0;
}