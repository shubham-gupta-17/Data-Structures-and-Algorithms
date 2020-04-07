
#include<iostream>
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
			if(a[i]>a[j])
		    swap(a[i],a[j]);

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
int main()
{  int n,temp=0,a[100];
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];



  // bubble_sort(a,n);

   //selection_sort(a,n);

   insertion_sort(a,n);

for(int i=0;i<n;i++)
cout<<a[i]<<endl;


}
