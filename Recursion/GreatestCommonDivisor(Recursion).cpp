  

#include<iostream>
using namespace std;

void greatestCommonDivisor(int a,int b)
{

    if(a != 0 && b!=0)
    {
        if(a>b)
        {
            greatestCommonDivisor(a%b ,b);
        }
        else
        {
            greatestCommonDivisor(a ,b%a);
        }
    }
    else
    {
       a=a>b?a:b;
       cout<<a;
    }
}

int main()
{
    cout<<"Jai Shri Krishna";
    int a,b;
    cin>>a>>b;
    greatestCommonDivisor(a,b);

    return 0;
}
