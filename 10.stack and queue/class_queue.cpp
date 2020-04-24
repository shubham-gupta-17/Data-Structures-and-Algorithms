#include<iostream>
#include<stack>
#include<climits>
class queue
{

public:
	int top_que=INT_MIN;
	stack<int> st;
	stack<int> st2;

	bool isEmpty()
	{
		if(st.size()==0 && st2.size()==0)
			return true;

		return false;
	}
	int size()
	return st.size()==0? st2.size():st.size();

	void push(int data)
	{	if(st.empty() && st2.empty()){
		top_que=data;
		st.push(data);
		}

		else if(!st.empty() && st2.empty())
			st.push(data);

		else if(st.empty() && !st2.empty())
			st2.push(data);	
	}

	void pop()
	{	if(!isEmpty())
		{
			if(st.size()!=0 && st2.size()==0){
				while(st.top()!=top)
				st2.push(st.top());
				top=st2.top();
				st.pop();
			}

			else if(st.size()==0 && st2.size()!=0)
			{	if(top==st2.top()) st2.pop();
				top=st2.top();

				while(st2.size()!=0)
				{
					st.push(st.top());
					st2.pop();
				}
			}
		
		}

		void front()
		return top;
		
	}

}