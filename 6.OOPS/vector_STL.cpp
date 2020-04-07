#include<iostream>
#include<algorithm>
using namespace std;
class vector{
   public:
   int max_size=1;
   int *arr=NULL;
   int current_size=0;

   vector()
   {
       arr=new int[max_size];
   }
   
   vector(int size,int data)
   {
       arr=new int[size];
       for(int i=0;i<size;i++)
       arr[i]=data;
   }

   void reserve(int max_size)
   {
       arr=new int[max_size];
   }

   void push_back(int data)
   {
       if(current_size==max_size)
       {
           
           int *oldarr=arr;   // we are not creating a new array here bcoz it will be a local variable and will
                            // get deleted automatically
           arr= new int[2*max_size];
           for(int i=0;i<current_size;i++)
           arr[i]=oldarr[i];
            
           max_size *=2;
        delete [] oldarr;    //we are deleting the array stored in heap ,oldarr is a local variable in stack
                             // so it will be deleted automatically, if we don't delete it memory will get fulledat one point

       }
       arr[current_size]=data;

       current_size++;
    
       
   }

   void print()
   {
       for(int i=0;i<current_size;i++)
       cout<<arr[i]<<" ";
   }

   void pop_back()
   {
       //cout<<arr[current_size-1];
      // delete (arr+current_size-1);
       current_size-=1;
   }

   void at(int index)
   {
       cout<<arr[index-1];
   }
   int& operator[](int index) // here we are returning the variable by reference 
   {
       return arr[index-1];
   }

   int size()
   {  
       return current_size;
   }
};
ostream& operator<<(ostream &x,vector &y)  //x is a reference variable to cout and a local variable
{   cout<<endl;

    for(int i=0;i<y.size();i++)
    x<<y[i]<<" ";

    cout<<endl;
    y.print();

    return x;
}
int main()
{  
    //int a[]={6,5,4,8,9};
   // sort(a,a+5,comp);
    int n;
    vector a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        a.push_back(b);
    }
    a.pop_back();
    vector b(a);  // it will make a shallow copy means if a changes b will also change

    //ways to print vector
    a.print();
    
    a[1]+=500;
    cout<<a[1]; //we need to do opeator overloading bcoz our class doesnot know the meaning of square brackets
    
    cout<<a<<b; //this will print complete vector
}