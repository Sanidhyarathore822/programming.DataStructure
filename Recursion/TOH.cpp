#include<iostream>
using namespace std;

void hanoiTower(int n,char source,char destination,char helper)
{
    if(n!=0)
    {
        //Moving n-1 disk to source to helper
        hanoiTower(n-1,source,helper,destination);
        cout<<"\nMove Disk "<<n<<" from " <<source<<" to "<<destination;
        //Moving n-1 disk from helper to destination
        hanoiTower(n-1,helper,destination,source);
    }
    else
    return;
}

int main()
{
    int n=3;
    cout<<"\n       Jai Shri Krishna\n";
    cout<<"\nEnter the no. of Disk:";
  //  cin>>n;
    cout<<"Note: 'A' is Source, 'B' is Destination, 'C' is Helper\n";

    hanoiTower(n,'A','B','C');

    return 0;

}