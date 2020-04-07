#include<iostream>
using namespace std;
int main()
{
    string arr[100];
    for(int i=0;i<3;i++)
    getline(cin,arr[i]);

    int n;
    for(int i=0;i<3;i++){
     n=arr[i].length();
     for(int j=0;j<n;j++){
     cout<<arr[i][j]<<" ";
     }
     cout<<endl;

    }

}
