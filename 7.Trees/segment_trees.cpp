#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
void segment_tree_construct(int *arr,int *segment,int start,int end,int position) //this create an array
{
	if(start==end)
	{
		segment[position]=arr[end];
		return ;
	}

	int mid=(start+end)/2;
	segment_tree_construct(arr,segment,start,mid,2*position+1);
	segment_tree_construct(arr,segment,mid+1,end,2*position+2);

	segment[position]=min(segment[2*position+1],segment[2*position+2]);
	return ;
}
Node *create(int *arr,int start,int end)
{
	if(start==end)
	{
		return new Node(arr[end]);
	}

	int mid=(start+end)/2;
	Node *left=create(arr,start,mid);
	Node *right=create(arr,mid+1,end);

	return new Node(min(left->data,right->data));
}
int find_range_query(int *segment,int start,int end,int qstart,int qend,int position)
{
	if(qstart<=start && qend>=end)
		return segment[position];

	else if(qstart>end || qend<start)
		return INT_MAX;

	int mid=(start+end)/2;
	return min(find_range_query(segment,start,mid,qstart,qend,2*position+1),find_range_query(segment,mid+1,end,qstart,qend,2*position+2));
}
int main()
{
	int n;
	cin>>n;

	int *arr=new int[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<endl;

	int m=n*2-1;
	int *segment=new int[m];

	segment_tree_construct(arr,segment,0,n-1,0);
    for(int i=0;i<m;i++)
    cout<<segment[i]<<" ";

	// range  query
	int qstart=2,qend=8;
	//cin>>qstart>>qend;
	int ans=find_range_query(segment,0,n-1,qstart,qend,0);
	cout<<ans;

	// update the given indexes
	int id;
	int number;
	cin>>id>>number;
	update(id,number,0,n-1,0);
	return 0;
}