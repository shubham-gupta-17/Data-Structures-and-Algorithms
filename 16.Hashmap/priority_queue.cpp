#include<iostream>
#include"priority_queue.h"
using namespace std;
int main()
{
	vector<int> arr={5,4,3,2,1};
	bool max=false;    //create min pq
	priority_queue pq(max,arr);
	pq.add(9,max);
	pq.add(8,max);
	pq.add(7,max);
	pq.add(6,max);
	pq.add(10,max);
	//pq.remove(1,max);
	
	pq.display();
	return 0;

}