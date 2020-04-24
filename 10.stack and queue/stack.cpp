// #include<iostream>
// #include<stack>
// #include<vector>
// using namespace std;
// void right_great(vector<int>&a)
// {
//     stack<int> st;
//     vector<int> ans(a.size(),-1);
//     for(int i=0;i<a.size();i++)
//     {
//         while(st.size()!=0 && a[st.top()]<a[i])
//         {
//             int index=st.top();
//             st.pop();
//             ans[index]=i;
//         }
//         st.push(i);
//     }

//     vector<int> b;
//     for(int i=0;i<ans.size();i++)
//     {   int j=ans[i];
//         if(j==a.size())
//             b.push_back(-1);

//         elsebn                                    
//         b.push_back(a[j]);
//     }
//     for(int i=0;i<b.size();i++)
//         cout<<b[i]<<endl;
// }
// int main()
// {
//     vector<int> a={4,2,3,2,2,4,5,6,4,3,2,1};
//     right_great(a);


// }
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void right_great(vector<int>&a)
{
    stack<int> st;
    vector<int> ans(a.size(),-1);
    for(int i=0;i<a.size();i++)
    {
        while(st.size()!=0 && a[st.top()]<a[i])
        {
            int index=st.top();
            st.pop();
            ans[index]=i; // ans[index]=a[i];// this will store than greater on right
        }
        st.push(i);
    }

    vector<int> b;
    for(int i=0;i<ans.size();i++)
    {   int j=ans[i];
        b.push_back(a[j]);
    }
    for(int i=0;i<b.size();i++){
            if(b[i]==0)
            cout<<"-1"<<" ";
            else
            cout<<b[i]<<" ";
       } 
        return ;
        
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n,-1);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    right_great(a);


}