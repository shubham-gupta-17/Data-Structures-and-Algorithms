#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
bool compare(int a,int b,bool max)
{
	if(max==true)
	  return a<b;
	else
	return a>b;
}
void down_heapify(bool max,int i,int n)
{
	int left=2*i+1;
	int right=2*i+2;
	int root=i;  // assume root is minimum
	if(left<=n && compare(arr[root],arr[left],max))
	  root=left;
	if(right<=n && compare(arr[root],arr[right],max))
	  root=right;

	if(root!=i)
	{
		swap(arr[i],arr[root]);
		down_heapify(max,root,n);
	}
	return ;

}
void create(vector<int>&arr,bool max)
{
	for(int i=arr.size()-1;i>=0;i--)
		down_heapify(max,i,arr.size()-1);
}
int main()
{
    arr={3,2,1,5,6,4};
    bool max=true;
    create(arr,!max);
    int last=arr.size()-1;
    swap(arr[0],arr[last]);
    cout<<max<<!max<<max<<endl;
    while(last-->0)
    {
        down_heapify(!max,0,last);
        swap(arr[0],arr[last]);
    }

    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";

    return 0;
}