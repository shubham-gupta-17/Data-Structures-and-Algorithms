#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[100],max_number=-1000000000;
	for(int i=0;i<n;i++){
	cin>>a[i];

	  if(max_number<a[i])
	  max_number=a[i];

	}
	cout<<max_number;

return 0;
}
