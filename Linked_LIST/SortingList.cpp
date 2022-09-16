#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int info;
    struct node* next;
};

struct node* START=NULL;

void insert(int data)
{
    struct node* t;
    t=new node;
    t->info=data;
    t->next=NULL;

    if(START==NULL)
    {
        START=t; 
    }
    else
    {
        struct node* temp=START, *prev;
        if(START->info > t->info)
        {
            t->next=START;
            START=t;
        }
        else 
        {
            while(temp!=NULL && temp->info<data)
            {
                prev=temp; 
                temp=temp->next;

            }
            prev->next=t;
            t->next=temp;

        }
    }
}

void displayList()
{   
    struct node*t=START;

    cout<<"\n LIST is: ";
    while(t!=NULL){
        cout<<t->info<<"    ";
        t=t->next;
    }
}


int main()
{
    cout<<"Jai Shri Krishna\n";
    insert(45);
    insert(67);
    insert(100);
    insert(23);
    insert(76);
    displayList();
    insert(3);
    insert(56);
    insert(300);
    displayList();
    return 0;
}
