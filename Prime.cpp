#include<iostream>
using namespace std;
int main()
{   int n,c=0;
    cin>>n;;
    for(int i=2;i<=n/2;i++)
     {
        if(n%i==0){
        cout<<"NOT A PRIME"<<endl;
        c++;
        break;
        }
     }

     if(c==0)
     cout<<"IS PRIME";

    // print all prime number between 2 and upper limit

    int upper_limit;
    cin>>upper_limit;
    for(int i=2;i<upper_limit;i++){
     c=0;
      for(int j=2;j<(i/2);j++)

    {    if(i%j==0){
            c++;
           break;}


    }
    if(c==0)
    cout<<i<<endl;
    }

}
