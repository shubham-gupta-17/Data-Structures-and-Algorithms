#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{
  return a>b;  /// sorts in descending order
  return a<b;  /// sorts in ascending order

}
int main()
{
vector<int> arr   ;  ///declaration of vector methd 1
    cout<<arr.size()<<endl<<sizeof(arr)<<endl;
    arr.push_back(10);
    cout<<sizeof(arr)<<endl;  ///doubt
    cout<<arr.size()<<endl;
    cout<<a;


  vector<int> a1; ///declaration of vector method 2
   a1.reserve(100);  /// it will reserve 100 blocks for array and after filling up of those size will increase.
   int n;
   cin>>n;
  a.end=n;
   for(int i=0;i<n;i++)
   {
    int b;
    cin>>b;
    a1.push_back(b);
   }

    a1.capacity();  /// it will the maximmum size of array til now.
/// how to sort a vector
   sort(a1.begin(),a.end(),compare);

   for(int i=0;i<n;i++) cout<<a1.at(i);  /// or use a[i];



   vector<int >a;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
    {       ///take inputs in a vector dynamically
    int b;
    cin>>b;
    a.push_back(b);
    }

   for(int i=0;i<n;i++)cout<<a.at(i)<<endl;


   a.pop_back()        /// remove an element from last
   a.erase(a.begin()+3);   /// remove by index

   a.erase(remove(a.begin(),a.end(),2),a.end()); ///remove by value , if a.end() is not written than it will remove 2 only once and return

   cout<<a.empty()<<endl<<endl;
   a.clear(); /// to clear the vector
   cout<<a.empty(); ///to find out whether vector is empty  or not it returns a bool

   for(int i=0;i<a.size();i++)cout<<a.at(i)<<endl;

    cout<<endl<<a.size();



    cout<<a1.max_size(); /// it will tell the maximum size a vector can take which depends upon system







}
