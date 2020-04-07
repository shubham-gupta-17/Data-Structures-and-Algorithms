#include<bits/stdc++.h>
using namespace std;
void permutation_infinite(vector<int>&coins,int target,string ans,int start_index)
{
    if(target==0)
    {
    cout<<ans<<endl;
    return;
    }
    for(int i=start_index;i<coins.size();i++)
    {
        if(target-coins[i]>=0)
        permutation_infinite(coins,target-coins[i],ans+to_string(coins[i]),0);
    }
    return;
}
void combination_infinite(vector<int>&coins,int start_index,int target,string ans)
{
    if(target==0)
    {
        cout<<ans<<endl;
        return;
    }

    for(int i=start_index;i<coins.size();i++)
    {
        if(target-coins[i]>=0)
        combination_infinite(coins,i,target-coins[i],ans+to_string(coins[i]));
    }
    return ;
}
void combination_not_infinite(vector<int>&coins,int start_index,int target,string ans)
{
    if(target==0)
    {
        cout<<ans<<endl;
        return;
    }

    for(int i=start_index;i<coins.size();i++)
    {
        if(target-coins[i]>=0)
        combination_infinite(coins,i+1,target-coins[i],ans+to_string(coins[i]));
    }
    return ;
}
void permutation_not_infinite(vector<int>&coins,int target,string ans,int start_index,vector<bool>&check)
{
    if(target==0)
    {
    cout<<ans<<endl;
    return;
    }
    for(int i=start_index;i<coins.size();i++)
    {
        if(target-coins[i]>=0 && !check[i]){
            check[i]=true;
        permutation_not_infinite(coins,target-coins[i],ans+to_string(coins[i]),0,check);
        check[i]=false;
        }
    }
    return;
}
int main()
{
    vector<int> coins{2,3,5,7};
    vector<bool> check(coins.size(),false);
    cout<<" PERMUTATION WITH REPETATION: "<<endl;
    permutation_infinite(coins,10," ",0);
    cout<<endl<<"COMBINATION WITH REPETATION: "<<endl;
    combination_infinite(coins,0,10," ");
    cout<<endl<<"COMBINATION WITHOUT REPETATION: "<<endl;
    combination_not_infinite(coins,0,10," ");
    cout<<endl<<"PERMUTATION WITHOUT REPETATION: "<<endl;
    permutation_not_infinite(coins,10," ",0,check);

    return 0;

}