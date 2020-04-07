
#include<bits/stdc++.h>
using namespace std;
char* print(string p,char*b,char c[],int n,int *d,int e[])
{
  cout<<p<<endl;   /// how to pass a string

  for(int i=0;i<n;i++)               ///methods to pass a character array and integer array
    cout<<b[i]<<" "<<c[i]<<endl;

  for(int i=0;i<n-1;i++)
  cout<<d[i]<<" "<<e[i]<<endl;

  char *f=new char[n+1];     ///it is dynamic array its scope remains for the entire function runtime
  ///char f[12];              /// it's scope remain to the time char print function is executed hence it can not be passed
  for(int i=0;i<n+1;i++)
  cin>>f[i];

  return f;      /// we are returning the address of array f;

}
int main(){
   string s="I am Best";
   int i=0;
   while(s[i]!='\0')
   {
     cout<<s[i]<<" ";
     i++;

   }
   cout<<endl;
   char a[]="Hello_world";
   int c[]={1,2,3,4,5,6,7,8,9,10,11};
    char *s1=print(s,a,a,sizeof(a),c,c);     ///it is a pointer because we are taking a address in it which is of a character array
  //  cout<<s1;


 /// to create a pointer pointing to integer array
   int n,a[10]={1,2,3,4,5};
    cin>>n;
    int *p=a;
    int *m=&n;
    cout<<m<<"  "<<*m<<endl;
    cout<<p<<endl<<&a<<endl;
    for(int i=0;i<5;i++)
      cout<<(p+i)<<endl;

 /// How to create a pointer pointing to char array
    char b[]="hello";
    string s="hello";
    char *p1=b;
      cout<<&b<<endl<<*(p1+1)+1<<endl<<&p1<<endl<<p1<<endl;
//      cout<<sizeof(b)<<endl<<s.length();
      for(int i=0;i<sizeof(b);i++)
        cout<<*(p1+i);
    char c;
    cin>>c;
    char *d=&c;
    cout<<endl<<*d;



 /// store array in stack
    int a[100];
   int *p=a;
   for(int i=0;i<5;i++)
   {
      cin>>p[i];      /// take input in an array using pointer
      cin>>*(p+i);
      cin>>a[i];
      //a[i]=*p;
   }

   for(int i=0;i<5;i++)
   cout<<p[i];
    cout<<*(p+i);
    cout<<a[i];

    /// store array in heap
    int *a=new int[5];
    for(int i=0;i<5;i++)
     cin>>*(a+i);

     for(int i=0;i<5;i++)
     cout<<a[i];

   /// store a 2-D array in heap
     int **a=new int*[3];
     for(int i=0;i<3;i++)
     *(a+i)=new int[4];


     for(int i=0;i<3;i++)
     {
        for(int j=0;j<3;j++)
        cin>>*(*(a+i)+j);

     }


     for(int i=0;i<3;i++)
     {
     for(int j=0;j<3;j++)
     cout<<a[i][j];
     }


}
