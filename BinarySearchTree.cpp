#include<iostream>
#include<stdio.h>
using namespace std;

struct BSTNode
{
    int info;
    struct BSTNode* left;
    struct BSTNode* right;
};
struct BSTNode* findNode(struct BSTNode* root,int data)
{
    if(root==NULL)
        return 0;
    else 
    if(data>root->info) //if data is greater than root node than we will
        return findNode(root->right,data);     //search in right side
    else 
    if(data<root->info)
        return findNode(root->left,data);
    
    return root;
}
struct BSTNode* insertNode(struct BSTNode* root,int data)
{
    cout<<"JAI SHRI KRISHNA 1\n";
    struct BSTNode* newNode=(struct BSTNode*)malloc(sizeof(struct BSTNode));
    struct BSTNode* p;
    cout<<"JAI SHRI KRISHNA 2\n";
    newNode->info=data;
    newNode->left=newNode->right=NULL;
    cout<<"JAI SHRI KRISHNA 3\n";
    if(root==NULL)
    {
        root=newNode;
        cout<<"JAI SHRI KRISHNA 4\n";
    }
    else
    {
        cout<<"JAI SHRI KRISHNA 5\n";
        p=root;
        while (p!=NULL)
        {
            cout<<"JAI SHRI KRISHNA WHILE\n";
            if(p->info>=data)
            {
                if(p->left==NULL)
                {
                    p->left=newNode;
                    break;
                }
                p=p->left;
            }
            else
            if(p->info<data)
            {
                if(p->right==NULL)
                {
                    p->right=newNode;
                    break;
                }
                p=p->right;
            }

        }   
    }
    return root;
}
void inOrder(struct BSTNode* root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->info<<"   ";
        inOrder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    int data;
    struct BSTNode* root=NULL;    
    //root=(struct BSTNode*)malloc(sizeof(struct BSTNode));
    root=insertNode(root,34);
    root=insertNode(root,21);
    root=insertNode(root,1);
    root=insertNode(root,10);
    root=insertNode(root,38);
    root=insertNode(root,29);
    root=insertNode(root,19);
    root=insertNode(root,100);
    root=insertNode(root,3422);
    root=insertNode(root,212);
    root=insertNode(root,193);
    root=insertNode(root,345);
    //root=findNode(root,67);
    inOrder(root);
    
    if(findNode(root,21)) 
        cout<<"\nElement found";
    else
        cout<<"\nElement Not Found";
    return 0;
}
