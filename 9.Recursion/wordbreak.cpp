#include<bits/stdc++.h>
using namespace std;
int countt=0;
/*void word_break(vector<string>&words,string ans,string word)
{
    if(words.size()==0)
    {
        cout<<ans<<endl;
        countt++;
        return ;
    }
    for(int i=0;i<word.length();i++)
    {   
        string temp=word.substr(i,i+1);
        word_break(words,ans+" "+temp,word);

    }
  return ;
}*/
int main()
{
    vector<string> words={"i","like","sam","sung","samsung"};
    string word ="ilikesamsung";
   // word_break(words," ",word);

    cout<<word.substr(0,1);

    return 0;
}