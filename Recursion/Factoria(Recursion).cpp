//Program will find the Factorial it wil also find the List of factorials
//and  find the number as well

#include<iostream>
using namespace std;

void checkFactorial(int n);
void factorialList(int n);
int factorial(int n)
{
    static int result=1;
    if(n>0)
    {
       result = result*n;
       factorial(n-1);
    }
    else
    {
        return result;
    }
    return result;
}

void checkFactorial(int n)
{
    static int result=1;
    static int i=1;
    
    if(n==1)
    {
        cout<<"Number = 1 and 0";
    }
    else
    if(result==n)
    {
        cout<<n<<" is a Factorial of "<<--i;
        return;
    }
    else 
    if(result<n)
    {
        result*=i;
        i++;
        checkFactorial(n);
    }
    else
    {
        cout<<n<<" is a not a Factorial of any Number";
        return;
    }

}

void factorialList(int n)
{
    int result;
    
        for(int i=1;i<=n;i++)
        {    
            result=factorial(i);
            cout<<i<<"! = "<<result<<endl;
        }
    


}

int main()
{
    int i,n;

    cout<<"Jai Shri Krishna"<<endl;

    cout<<"Which task you want to perform:";
    cout<<"\n1. Finding Factorial of Number.";
    cout<<"\n2. List of Factorials of Number upto n.";
    cout<<"\n3. Finding Number from Factorial.\n";
    cin>>i;

    if(i==1)
    {
        int result;
        cout<<"Enter the number: ";
        cin>>n;
        result=factorial(n);
        cout<<"Factorial of "<<n<<" is "<<result;
    }
    else
    if(i==2)
    {
        cout<<"Enter the value of n: ";
        cin>>n;
        factorialList(n);
    }
    else
    if(i==3)
    {
        cout<<"Enter the Factorial: ";
        cin>>n;
        checkFactorial(n);
    }
    else
    {
        cout<<"Enter the Valid Entry ";
    }

    return 0;
}