#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int digit=0,reverse_number=0;

  for(n;n>0;n/=10){  // find number of digits
   digit++;
   reverse_number=reverse_number*10 + n%10;  // print number in reverse order
   }

  cout<<digit<<endl<<reverse_number<<endl;
  // Shirt operators
  int a;
  cin>>a;
  cout<< "left shift 'a' by 1 : "<< (a<<1)  << endl;
	cout<< "right shift 'a' by 1 : "<<(a>>1)  << endl;


}
