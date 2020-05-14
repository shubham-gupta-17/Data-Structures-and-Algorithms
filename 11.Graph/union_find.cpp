#include<iostream>
#include<vector>
using namespace std;
void construct(vector<vector<pair<int,int>>> &arr)
{
	addedge(arr,0,1,10);
	addedge(arr,0,3,10);
	addedge(arr,1,2,10);
	addedge(arr,2,3,40);
	addedge(arr,3,4,20);
	addedge(arr,4,5,20);
	addedge(arr,4,6,30);
	addedge(arr,0,1,10);
	addedge(arr,0,1,10);
	addedge(arr,0,1,10);


}
int main()
{
	construct();
}