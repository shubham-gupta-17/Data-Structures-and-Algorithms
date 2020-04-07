#include<bits/stdc++.h>
using namespace std;
int permutation(vector<int>&coins,int start_index,int target,string ans)
{   if(target==0)
     {
         cout<<ans<<endl;
         return 1;
     }
     int count=0;
     for(int i=start_index;i<coins.size();i++)
     {  if(target-coins[i]>=0)
         count+=permutation(coins,0,target-coins[i],ans+" " +to_string(coins[i]));
     }
  return count;
}
int main()
{
    vector<int> coins{2,3,5,7};
    cout<<permutation(coins,0,10," ");   //permutation(array,start_index,taregt number)
}
