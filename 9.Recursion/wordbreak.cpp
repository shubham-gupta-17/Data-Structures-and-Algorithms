#include<bits/stdc++.h>
using namespace std;
void word_break(string s,unordered_map<string,bool>&map,string ans,vector<string>&arr)
{
    if(s.length()==0)
    {
        ans.pop_back();
        arr.push_back(ans);
        return;
    }

    for(int i=0;i<s.length();i++)
    {
        string s1=s.substr(0,i+1);
        if(map.find(s1)!=map.end() && !map[s1])  // to use every word ,multiple times remove !map[s1]
        {
            map[s1]=true;
            word_break(s.substr(i+1),map,ans+s1+" ",arr);
        }
    }
    return;
}

void word_break_optimize(string s,unordered_set<string>&map,vector<bool>&vis,vector<string>&arr,string ans1)
{
    if(s.length()==0 || s=="")
    {
        ans1.pop_back();
        arr.push_back(ans1);
        return ;
    }

    for(int i=0;i<s.length();i++)
    {
        string p=s.substr(0,i+1);
        bool ans=map.find(p)!=map.end();
        if(vis[i] && !ans )
            continue;
        else if(ans)
            word_break_optimize(s.substr(i+1),map,vis,arr,ans1+p+" ");
        else vis[i]=true;
    }
    return;

}
 bool wordBreak(string &s, vector<string>& wordDict) {
       
        for(string s1:wordDict)
            map.insert(s1);
        int n=s.length();
        vector<bool>dp(n+1,false);
        dp[n]=true;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<=n;j++)
            {  
                if(!dp[j]) continue;
                string s1=s.substr(i,j-(i));
                if(map.find(s1)!=map.end())
                {   cout<<s1<<" ";
                    dp[i]=dp[i]|| dp[j];
                 //break;
                }
            }
        }

        for(int i=0;i<=n;i++)
            cout<<dp[i]<<" ";
       return dp[0];
    }

//======================================================================================================================
    // top down1
74 665
142 112 54 69 148 45 63 158 38 60 124 142 130 179 117 36 191 43 89 107 41 143 65 49 47 6 91 130 171 151 7 102 194 149 30 24 85 155 157 41 167 177 132 109 145 40 27 124 138 139 119 83 130 142 34 116 40 59 105 131 178 107 74 187 22 146 125 73 71 30 178 174 98 113
    // word break 1
unordered_map<int,vector<string>>hash;
    set<string>map;
    vector<bool>vis;
   
    vector<string> word_break(string &s,int start)
    {    vector<string> arr;
        if(start==s.length()){
            //arr.push_back("");
            return arr;
        }
        
       if(hash.find(start)!=hash.end()) return hash[start];
        for(int i=start;i<s.length();i++)
        {   
            
            string s1=s.substr(start,i-start+1);
             if(map.find(s1)!=map.end())
             { // cout<<s1<<" ";
                vector<string> a=word_break(s,i+1);
                
                if(a.size()!=0){ 
                for(string s2:a)
                {   
                    if(i==s.length()-1) arr.push_back(s1);
                    else arr.push_back(s1+" "+s2); 
                }
            }
        }
    }
     for(string s3:arr)
         hash[start].push_back(s3);  
        return arr;
    }
vector<string> WordBreak(string s, vector<string>& wordDict) {
         for(string s1:wordDict)
            map.insert(s1);
            vis.resize(s.length(),false);
        
        vector<string>ans= word_break(s,0);
        
        return ans;
    }

//==================================================================================================================================
    //bottom up

    vector<string> word_break(string &s,int end)
    {    vector<string> arr;
        if(end==-1){
            arr.push_back("");
            cout<<arr.size()<<endl;
            return arr;
        }
        
       if(hash.find(end)!=hash.end()) return hash[end];
        for(int i=0;i<end;i++)
        {   
            
             string s1=s.substr(i,end-i);
             if(map.find(s1)!=map.end())
             {  
                vector<string> a=word_break(s,i);
                
                if(a.size()!=0){ 
                for(string s2:a)
                {   
                    if(i==0) arr.push_back(s1);
                    else arr.push_back(s2+" "+s1); 
                }
            }
             
        }
    }
     for(string s3:arr)
         hash[end].push_back(s3);  
        return arr;
    }
    vector<string> wordBreak(string &s, vector<string>& wordDict) {
         for(string s1:wordDict)
            map.insert(s1);
            vis.resize(s.length()+1,false);
        
        vector<string>ans= word_break(s,s.length());
        for(string s3:ans)
             cout<<s3<<" ";
        return ans;
    }

//==========================================================================================================================================
// both top down and bottom up will give tle bcoz everytime we are passing a string or an array hence best sol is first check if word is
// breakable or not if yes then only cut the string
// below is the best solution

    //word break 2
 unordered_set<string>map;
vector<bool>vis;
bool valid_break(string&s)
{   
           vector<bool>T(s.size()+1, false);
        T[0]=true;
        for(int i=1; i<=s.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(T[j]){
                    string word = s.substr(j, i-j);
                    if(map.find(word)!=map.end()){
                        T[i]=true;
                        break;
                    }
                }
            }
}
return T[s.size()];
}
vector<vector<string>> a;
void get_break(string&s,int start,vector<string>&path)
{
    if(start==s.length())
    {
        a.push_back(path);
        return ;
    }
    for(int i=start;i<s.length();i++)
    {   
        string s1=s.substr(start,i-start+1);
        //if(vis[i] || map.find(s1)==map.end()) continue;
        if(map.find(s1)!=map.end()){
            path.push_back(s1);
            get_break(s,i+1,path);
            path.pop_back();
        }
        //else vis[i]=true;
    }
    return ;
}
vector<string> wordBreak(string &s, vector<string>& wordDict) {
    
    int n=s.length();
    for(string word:wordDict)
        map.insert(word);
    vis.resize(s.length(),false);
    vector<string>arr;
    bool ans=valid_break(s);
    if(!ans) return arr;
    cout<<ans;
    
    vector<string>path;
    get_break(s,0,path);
    for(vector<string> b:a)
    {
        string s2="";
        for(string s3:b)
        {
            s2=s2+s3+" ";
        }
        s2.pop_back();
        arr.push_back(s2);
    }
    return arr;
}


void wordBreak()
{
     string s="ilikesamsung";
    vector<string> word={"i","like","sam","sung","samsung","likes","am"};

    // if we have to use every word in dictionary only once
    unordered_map<string,bool> map;
    for(string s:word)
        map[s]=false;
    vector<string>ans;
    word_break(s,map,"",ans);
    for(string s:ans)
        cout<<s<<endl;


    // optimize way to find word break and every word can be used multiple times
    unordered_set<string>set;
    for(string s:word)
        set.insert(s);
    vector<bool>vis(s.length(),false);
    vector<string>arr;
    word_break_optimize(s,set,vis,arr,"");
    for(string s:arr)
        cout<<s<<endl;


    // dp solution slower then memo bcoz of O(n2) complexity bcoz of loop
    word_break_dp(s,word);
    WordBreak(s,word);
    return ;
}

//===================================================================================================================================
vector<string> map={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>arr;
vector<string>* find(char ch,vector<string>*&ans)
    {  
        int n=ch-'0';
        int len=map[n].length();
        string s=map[n];
        vector<string>*arr=new vector<string>;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<ans->size();j++)
            {
                arr->push_back(ans->at(j)+s[i]);
            }
        }
     return arr ;
    }
void numeric_keypad()
{

        int n=digits.length();
         vector<string>*ans=new vector<string>;
         vector<string>arr;
        if(n==0){
            return arr;
        }
       
            char ch=digits[0];
            for(int i=0;i<map[ch-'0'].length();i++){
                string s="";
                 s+=map[ch-'0'][i];
                ans->push_back(s);
            }
      
        for(int i=1;i<n;i++)
        {
           ans=find(digits[i],ans);
        }
       
        for(int i=0;i<ans->size();i++)
            cout<<ans->at(i);
        
}
int main()
{
   
   wordBreak();
   numeric_keypad();

    return 0;

}