#include<iostream>
#include<queue>
#include<set>
using namespace std;
struct compare{
bool operator()(vector<int> const&a,vector<int> const&b)
{
    return a[0]>b[0];  // min priority_queue, for max use <
}
};
void find(){
   int arr[6]={3,4,5,1,2,6};
   int n=6;

   multiset<int> map(arr,arr+3);
  // map.erase(3);
   for(auto it=map.begin();it!=map.end();it++) cout<<(*it)<<" ";
   cout<<endl;
   auto it=next(map.begin(),n/2);

   int m=*prev(map.end(),(n/2)+1);
   cout<<*it<<" "<<m<<endl;
   cout<<(*(arr+3));
   return ;
}
int main()
{
  // priority_queue<vector<int>, vector<vector<int>> , compare> pq;
  // pq.push({3,100,150});
  // pq.push({2,200,250});
  // pq.push({1,300,250});
  // while(pq.size()!=0)
  // {
  //   cout<<pq.top()[0]<<" "<<pq.top()[1]<<" "<<pq.top()[2]<<endl;
  //   pq.pop();
  // }
  find();
  return 0;

}
