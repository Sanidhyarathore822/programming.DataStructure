#include<iostream>
#include<stdio.h>
using namespace std;

struct BinaryTreeNode
{
    int info;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;

};

struct BinaryTreeNode* createNode()
{
    int data;
    struct BinaryTreeNode* temp;

    cout<<"Enter your choice:\n1. create node\nAny other key for exit\n ";
    cin>>data;
    if(data!=1)
        return 0;
    else
    {
        temp=(struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
        cout<<"Enter the data: ";
        cin>>data;
        temp->info=data;
        cout<<"Enter the Left child of "<<data<<endl;
        temp->left=createNode();
        
        cout<<"Enter the Right child of "<<data<<endl;
        temp->right=createNode();

        return temp;
    }

}
void preOrder(struct BinaryTreeNode* root)
{
    if(root)
    {
        cout<<root->info<<"   ";
        preOrder(root->left);
        preOrder(root->right);

    }
}
void inOrder(struct BinaryTreeNode* root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->info<<"   ";
        inOrder(root->right);
    }
}
void postOrder(struct BinaryTreeNode* root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->info<<"   ";
    }
}



int main(int argc, char const *argv[])
{
  struct BinaryTreeNode* root=NULL;
  
  cout<<"Jai Shri Krishna\n";
  root = createNode();

  cout<<"\n\nTraversing in PreOrder:\n";
  preOrder(root);
  cout<<"\n\nTraversing in InOrder:\n";
  inOrder(root);
  cout<<"\n\nTraversing in PostOrder:\n";
  postOrder(root);
    return 0;
}

