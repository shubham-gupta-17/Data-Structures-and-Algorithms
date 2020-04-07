
#include<bits/stdc++.h>
using namespace std;
void selection_sort(int *a,int n)
{
		for(int i=0;i<n-1;i++)
		{ for(int j=i+1;j<n;j++)
		 {
			if(a[i]>a[j])
		    swap(a[i],a[j]);

		 }
		}

		   for(int i=0;i<n;i++)
		     cout<<a[i]<<endl;
}
void bubble_sort(int *a,int n)
{    for(int i=0;i<n-1;i++)
		{ for(int j=0;j<n-i-1;j++)
		 {
			if(a[j]>a[j+1])
		    swap(a[j],a[j+1]);

		 }
		}

		   for(int i=0;i<n;i++)
		     cout<<a[i]<<endl;

}
void insertion_sort(int a[],int n)
{
     int number=0;
     for(int i=1;i<n;i++)
     {  number=a[i];
        int j=0;
         for( j=i-1;j>=0 && a[j]>number;j--)
         	a[j+1]=a[j];

         a[j+1]=number;
     }

}
void wave_sort(int a[],int n)
{   ///1st Method
     for(int i=0;i<n;i++)
  {
      if(i%2==0)
      {    if(a[i]<a[i+1])
           swap(a[i],a[i+1]);
      }
      else
      {    if(a[i]>a[i+1])
            swap(a[i],a[i+1]);
      }
  }
   ///2nd Method:
  for(int i=0;i<n;i+=2)
  {
     if(i>0 && a[i-1]>a[i])
       swap(a[i],a[i-1]);

     if(i<n-1 && a[i+1]>a[i])
     swap(a[i],a[i+1]);
  }
}
bool comp(int a,int b)
{
   return a>b; ///sorts in descending order
   return a<b; ///sorts in ascending order
   return a.length()<b.length() ///sorts in increasing order of length if we have to sort strings


}
int main()
{  int n,temp=0,a[100];
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];



   bubble_sort(a,n);

   selection_sort(a,n);

   insertion_sort(a,n);
   
   wave_sort(a,n);

   sort(a,a+n,comp);  ///in-built sort function

for(int i=0;i<n;i++)
cout<<a[i]<<endl;


}
