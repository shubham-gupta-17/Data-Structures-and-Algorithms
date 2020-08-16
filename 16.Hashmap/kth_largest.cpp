#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
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
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        bool max=false;
        for(int i=0;i<n;i++) arr.push_back(nums[i]);
        create(arr,!max);
         int last=arr.size()-1;
            swap(arr[0],arr[last]);
            for(int i=0;i<k && last-->0 ;i++)
            {
                down_heapify(!max,0,last);
                swap(arr[0],arr[last]);
            }
        return arr[n-k];
    }

int main()
{
    vector<int>arr={10,243,2,1,3,43,50};
    int k=2;
    cout<<findKthLargest(arr,k);
    return 0;
}