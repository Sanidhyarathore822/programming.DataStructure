#include<iostream>
using namespace std;

void binary(int num)
{
    int bin;

    if(num>0)
    {    
        bin=num%2;          
        binary(num/2);
        cout<<bin;
    }
    else
        return;
    

}

int main()
{
    cout<<"\nJai Shri Krishna\n";

    int num=86;
    //cout<<"Enter a Number:"
    //cin>>num;

    binary(num);

    return 0;
}