#include<iostream>
#include<stdio.h>
using namespace std;

int size=0;

void swap(int *a,int *b)
{
    int t=*b;
    *b=*a;
    *a=t;
}

void heapify(int arr[],int size,int i)
{
    if(size == 1)
        cout<<"\nSingle Element in heap.\n";
    else
    {    
        int largest=i;
        int left=2*i+1,right=2*i+2;
        if(arr[largest] < arr[left] && left < size)
        {
            largest=left;
        }
        
        if(arr[largest] < arr[right] && right < size)
        {   
            largest=right;
        }
        
        if(largest != i)
        { 
            swap(&arr[i],&arr[largest]);
            heapify(arr,size,largest);
        }
    }    
        
}

void insert(int arr[],int num)
{
    if(size==0)
    {
        arr[0]=num;
        size+=1;
        cout<<"\n"<<num<<" is inserted.";
    }
    else
    {
        arr[size]=num;
        size+=1;
        for(int i=size/2-1;i>=0;i--)
        {
            heapify(arr,size,i);  
        }
    }

}

void deleteNode(int *arr)
{
    cout<<"Deleted node is :"<<arr[0];
    arr[0]=arr[--size];

    heapify(arr,size,0);

}

void displayHeap(int arr[])
{
    cout<<"\nHeap Is: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"  ";
    }
    
}

int main(int argc, char const *argv[])
{
    cout<<"Jai Shri Krishna\n";;

    int heap[10];
    
    insert(heap,34);
    insert(heap,67);
    insert(heap,11);
    insert(heap,3);
    insert(heap,4);
    displayHeap(heap);
    insert(heap,99);
    insert(heap,12);
    insert(heap,833);
    displayHeap(heap);
    deleteNode(heap);
    deleteNode(heap);
    deleteNode(heap);
    deleteNode(heap);
    deleteNode(heap);

    displayHeap(heap);
    
    return 0;
}
