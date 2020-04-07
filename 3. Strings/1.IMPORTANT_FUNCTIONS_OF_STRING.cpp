#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool comp(string a,string b)
{
    return a<b;  //it sorts in alphabatical increasing order

    return a>b;  //it sorts in alphabatical decreasing order

    return a.length()<b.length();  //it sorts in  increasing order of length

    return a.length()>b.length(); //it sorts in decreasing order of length

}
int main()
{
    string s={"hello world"};    // one way of taking input
     for(int i=0;i<s.length();i++)   // here we are iterating over each characters of a string
      cout<<s[i]<<" ";


   string s2;           // another way of taking input
    getline(cin,s2);
    cout<<s2;

    string s1;             // it will read only till spaces
    cin>>s1;
    cout<<s1;

     string s3("hello world");
     cout<<s3;

    string a[]={"apple", "banana","mango","orange","pineaple"};
      int n=sizeof(a)/sizeof(string);
      sort(a,a+n,comp);
      for(int i=0;i<n;i++)
      cout<<a[i]<<endl;



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
