#include <iostream>
using namespace std;
int main() {
int t,m=0;
cin>>t;
while(m<t){
  int n;
  cin>>n;
  int a[100000],b[100000];
  cin>>a[0];
  b[0]=a[0];

  for(int i=1;i<n;i++)
  {
  cin>>a[i];
   b[i]=b[i-1]+a[i];
  }
  int current_sum=0,max_sum=-100000000;
  for(int i=0;i<n;i++)
  {
     for(int j=i;j<n;j++)
     {
        current_sum=0
        current_sum =b[j]-b[i-1];

        if(current_sum>max_sum)
           max_sum=current_sum;


     }



  }

  cout<<max_sum<<endl;



   m++;
    }
    return 0;
}
