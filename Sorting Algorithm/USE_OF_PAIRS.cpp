#include<bits/stdc++.h>
using namespace std;
bool comp(pair<string,int>p1,pair<string,int>p2)
{
   if(p1.second==p2.second)
   return p1.first<p2.first;

   return p1.second>p2.second;


}
int main()
{
   int n;
   int x;
   cin>>x>>n;
   pair<string,int> emp[2000];

   for(int i=0;i<n;i++)
   {
      int salary;
       string name;
      cin>>name>>salary;
      emp[i].first=name;
      emp[i].second=salary;
   }

   sort(emp,emp+n,comp);

   for(int i=0;i<n;i++)
   { if(emp[i].second>x)
   cout<<emp[i].first<<" "<<emp[i].second;
    }







}
