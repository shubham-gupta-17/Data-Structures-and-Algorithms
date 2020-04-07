#include<bits/stdc++.h>
using namespace std;
int number_of_permutations=0,number_of_combinations=0;
int permutation(int size, vector<int> &numbers,int current_member, string ans,vector<bool>&check)
{
    if (current_member == size)
    {
        //cout << ans << endl;  this will print all the root to leaf path
        return 1;
    }

    int numberof_root_to_leaf_path = 0;
    for (int i = current_member; i < numbers.size(); i++)
    {   if(!check[i]){
          check[i]=true;
         cout<<ans + to_string(numbers[i])<<endl; // this will print all the combinations
        number_of_permutations ++;
        numberof_root_to_leaf_path += permutation(numbers.size(),numbers, 0, ans + to_string(numbers[i]) + " ",check);
        check[i]=false;
    }
        
    }
    return numberof_root_to_leaf_path;
}
int combinations(int size, vector<int> &numbers,int current_member, string ans)
{
    if (current_member == size)
    {
        //cout << ans << endl;  this will print all the root to leaf path
        return 1;
    }

    int numberof_root_to_leaf_path = 0;
    for (int i = current_member; i < numbers.size(); i++)
    {   
         cout<<ans + to_string(numbers[i])<<endl; // this will print all the combinations
        number_of_combinations ++;
        numberof_root_to_leaf_path += combinations(numbers.size(),numbers,i+1, ans + to_string(numbers[i]) + " ");
        
    }
    return numberof_root_to_leaf_path;
}
int main()
{   vector<int> numbers{1,2,3};
     vector<bool> check(numbers.size(),false);
     cout<<"PERMUTATIONS: ";
    cout<<permutation(numbers.size(),numbers,0," ",check)<<endl;
    cout<<endl<<number_of_permutations<<endl<<"COMBINATIONS: ";
    /*cout<<combinations(numbers.size(),numbers,0," ")<<endl;
    cout<<number_of_combinations;
    */
    return 0;
}