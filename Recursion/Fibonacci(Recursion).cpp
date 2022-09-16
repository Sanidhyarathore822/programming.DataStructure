//Program to find fibonacci series or checking wheather no. comes in series or not

#include<iostream>
using namespace std;

void fibonacciNumber(int number,int a,int b);
void fibonacci(int num,int a,int b)
{

    if(num>0)
    {
        cout<<a+b<<"   ";

        fibonacci(num-1,b,a+b);
    }
    else
    {
        return ;
    }
}


void fibonacciNumber(int number,int a,int b)
{
    if(number==a+b)
    {
        cout<<number<<" is a Fibonacci Number";
        return;
    
    }
    else
    if(number>a+b)
    {
        fibonacciNumber(number,b,a+b);
    }
    else
    {
        cout<<number<<" is not a Fibonacci Number";
        return;
    }

}


int main()
{
    cout<<"Jai Shri krishna\n";

    int a=0,b=1,task;
    int n;
    cout<<"Which operation you want to perform:\n1. Printing series upto n.\n";
    cout<<"2. Checking wheather no. comes in series or not.\n";
    
    cin>>task;
    
    if(task == 1)
    {
        cout<<"Enter the value of n: ";
    
        cin>>n;

        switch(n)
        {
            case 0: 
                    {cout<<"0   ";
                    break;
                    }
            case 1: 
                    {cout<<"0   1";
                    break;
                    }
            default:{
                    cout<<"0    1   ";
                    fibonacci(n-1,0,1);
                    }

        }
    
    }
    else 
    if(task==2)
    {

        cout<<"\nEnter the Number:";
        cin>>n;

        if(n==0 || n==1)
        cout<<"\n"<<n<<" is a fibonacci Number.";
        else
        fibonacciNumber(n,0,1); 
    
    }


    return 0;

}