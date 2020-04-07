#include<bits/stdc++.h>
using namespace std;
void  pass(vector<int>&a)
{   
    // remove & it will become pass by value and no changes will take place
    /*for(int i=0;i<5;i++)
    {
        int b;
        cin>>b;
        a.push_back(b);
    }*/
    a[1]+=10;
    a[2]+=22;
   
    return ;
}
void pass2(vector<int>*&a)
{
    a->push_back(10);
    a->push_back(20);
    return ;
}
int main()
{
    vector<int>a{1,2,3,4,5};
 
    pass(a);
    for(int n:a)
    cout<<n<<" ";
    
    cout<<endl;
    vector<int> *b=new vector<int>();
    pass2(b);
    for(int n:*b)
    cout<<n<<" ";
}