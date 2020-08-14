#include<iostream>
#include<vector>
class priority_queue{

	public :
	vector<int> pq;

	int size()
	{
		return pq.size();
	}

	int top()
	{
		return pq[0];
	}

	void downheapify(int p_idx)
	{
		int left_idx=2*p_idx+1;
		int right_idx=2*p_idx+2;

		int max_idx=p_idx // let that parent is max value in array and store its value

		if(left_idx< pq.size() && pq[left_idx]>pq[max_idx]) max_idx=left_idx;

		if(right_idx < pq.size() && pq[right_idx] > pq[max_idx])  max_idx=right_idx;
	}
};