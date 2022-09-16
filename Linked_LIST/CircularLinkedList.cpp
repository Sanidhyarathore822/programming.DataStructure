#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int info;
    struct node* next;
};

struct node* LAST=NULL;

struct node* createNode()
{
    return (struct node*)malloc(sizeof(struct node*));
}



void viewList()
{
    struct node* t;
    if(LAST == NULL)
        printf("\nList is EMPTY");
    else
    {
        t=LAST->next;
        do
        {
            printf("|   %d  | ",t->info);
            t=t->next;
        } while (t!=LAST->next);
        
    }
}
void insertAtBeg(int data)
{
    struct node* temp=createNode();

    temp->info=data;
    temp->next=LAST->next;
    LAST->next=temp;
}
void insertToEmpty(int data)
{
    struct node* temp=createNode();
    temp->info=data;
    temp->next=temp;
    LAST=temp;

    //cout<<temp->next<<" is equal "<<LAST->next;
}
void insertAtEnd(int data)
{
    struct node* temp=createNode();

    temp->info=data;
    temp->next=LAST->next;
    LAST->next=temp;
    LAST=temp;

}
void insertAfter(int data,int after)
{
    struct node* temp,*a;
    temp=LAST->next;
    int flag=0;

    do
    {
        if(temp->info==after)
        {
            a=(struct node*)malloc(sizeof(struct node));
            a->info=data;
            a->next=temp->next;
            temp->next=a;

            if(temp==LAST)
            {
                LAST=a;
            }
            flag=1;

        }
        temp=temp->next;

    } while (temp!=LAST->next);
    
    if (flag!=1)
    {
        cout<<endl<<after<<" is not in the list.";
    }
  
}
void deleteNode(int data)
{
    struct node* p,*q;
    int flag=0;

    if(LAST==NULL)
        cout<<"\nList is Empty.";
    else
    if(LAST==LAST->next && LAST->info==data)
    {
        
        LAST==NULL;
        cout<<"Flag 1111";
        free(LAST->next);
        flag=1;
    }
    else
    if(LAST->next->info==data)
    {
        p=LAST->next;
        LAST->next=LAST->next->next;
        free(p);
        flag=1;

    }
    else if(LAST->info==data)
    {
        p=LAST->next;
        flag=1;
        while(p->next!=LAST)
        {
            p=p->next;
        }
        q=LAST;
        p->next=LAST->next;
        LAST=p;
        free(q);
    }
    else 
    {
        p=LAST->next;

        while(p->next!=LAST)
        {
            if(p->next->info==data)
            {
                flag=1;
                q=p->next;
                p->next=q->next;
                free(q); 
                break;  
            }
            p=p->next;

        }
    }
    if(flag==0)
    {
        cout<<data<<" is not in the list.";
    }



}
void createList()
{
    int n,data;
    cout<<"Enter the size of LIST: ";
    cin>>n;

    if(n>0)
    {
        cout<<"Enter first data: ";
        cin>>data;
        insertToEmpty(data);
    }

    for(int i=1;i<n;i++)
    {
        cout<<"Enter data: ";
        cin>>data;
        insertAtEnd(data);
    }

}


int main()
{
    cout<<"Jai Shri Krishna\n";

    int a,data,after;

    cout<<"1. Creating List of size n.\n";
    cout<<"2. Insert at End\n";
    cout<<"3. Insert at Start\n";
    cout<<"4. Insert in Empty List\n";
    cout<<"5. Delete\n";
    cout<<"6. View List\n";
    cout<<"7. Insert After\n";
    cout<<"8. exit\n";

    while(1)
    {
        cout<<"\nENTER YOUR CHOICE: ";
        cin>>a;

        switch (a)
        {
        case 1:
            {   
                createList();
                viewList();
                break;
            }
        case 2:
            {   
                cout<<"Enter an Element: ";
                cin>>data;
                insertAtEnd(data);
                viewList();
                break;
            }
        case 3:
            {  
                cout<<"Enter an Element: ";
                cin>>data; 
                insertAtBeg(data);
                viewList();
                break;
            }
        case 4:
            {   
                cout<<"Enter an Element: ";
                cin>>data; 
                insertToEmpty(data);
                viewList();
                break;
            }
        case 5:
            {   
                cout<<"Enter an Element you want to DELETE: ";
                cin>>data; 
                deleteNode(data);
                viewList();
                break;
            }
        case 6:
            {   
                viewList();
                break;
            }
        case 7:
            {   
                cout<<"Enter an Element you want to INSERT: ";
                cin>>data;
                cout<<"Enter Element value after new value to be INSERT: ";
                cin>>after; 
                insertAfter(data,after);
                viewList();
                break;
            }
        case 8:
            {   
                cout<<"\n\n****** Hare RAMA Hare RAMA ******\n";
                cout<<"****** RAMA RAMA Hare Hare ******\n";
                cout<<"****** Hare KRISHNA Hare KRISHNA ******\n";
                cout<<"****** KRISHNA KRISHNA Hare Hare ******\n";
                
                exit(0);
                
                break;
            }
        
        default:
            {
                cout<<"\n Choose valid argument.";
                cout<<"\n\n****** Hare RAMA Hare RAMA ******\n";
                cout<<"****** RAMA RAMA Hare Hare ******\n";
                cout<<"****** Hare KRISHNA Hare KRISHNA ******\n";
                cout<<"****** KRISHNA KRISHNA Hare Hare ******\n";
                break;
            }
        }



    }
    

    return 0;
}