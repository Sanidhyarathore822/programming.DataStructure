#include<iostream>
#include<stdio.h>
using namespace std;


struct node
{
    int info;
    struct node *next;
    //This is our Node
};

struct node* START=NULL; //This is our Start Pointer


struct node* createNode()   //return the address of node
{
    struct node *p;             //pointer 
    p=(struct node *)malloc(sizeof(struct node)); //memory allocation
    return p;
    //This function creates node 
}

void insert(int data)
{
    struct node *temp;  //creating a pointer to store a address
    temp=createNode();     //creating node and storing addres in temp
    
    temp->next=NULL;       
    temp->info=data;

    if(START == NULL)
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
struct node* reverseLinkedList()
{
    struct node* t2=NULL,*t1=NULL;

    cout<<"Reverse List Is: ";
    while(START!=NULL)
    {
        t2=START->next;
        START->next=t1;
        t1=START;   
        START=t2;
    }
    
    return t1;

}
void traverse(struct node *START)
{
    struct node* a=START;

    cout<<"List Is: ";
    while(a!=NULL)
    {
        printf("\n ____\n");
        printf("| %d | \n",a->info);
        printf(" ''''\n |");
        
        a=a->next;
    }
    

}




int main()
{
    int data;
    printf("Jai Shri Krishna\n");
    printf("This programs allow user to insert a node at following point:");
    printf("\n1. At the beginning\n2.At the end\n3. After particular node.\n");

    printf("Enter the data: ");
    scanf("%d",&data);
    insert(data);
    printf("Enter the data: ");
    scanf("%d",&data);
    insert(data);
    printf("Enter the data: ");
    scanf("%d",&data);
    insert(data);
    printf("Enter the data: ");
    scanf("%d",&data);
    insert(data);

    START=reverseLinkedList();
    traverse(START);
    return 0;
}