#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class priority_queue{
	public:
vector<int> arr;
priority_queue(bool max,vector<int>&ans)
{	
	for(int i=0;i<ans.size();i++)
	  arr.push_back(ans[i]);
	create(arr,max);
}

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
	{
		down_heapify(max,i,arr.size()-1);
	}
}
void up_heapify(bool max,int i)
{
	int p=(i-1)/2; //assume added ele is smaller than its parent
	if(p>=0 && compare(arr[p],arr[i],max))
	{
		swap(arr[p],arr[i]);
		up_heapify(max,p);
	}
	return ;
}
void add(int n,bool max)
{
	arr.push_back(n);
	up_heapify(max,arr.size()-1);
}
void remove(int a,bool max)  // it will remove from top
{
	
	swap(arr[0],arr[arr.size()-1]);
	arr.pop_back();
	down_heapify(max,0,arr.size()-1);
	return ;
}
void display(){
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
  return;
}

};
