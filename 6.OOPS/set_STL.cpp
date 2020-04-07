#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.get(); // clear the buffer as getline will treat new line after n as an input
    string s;
    getline(cin,s);
    cout<<n<<endl<<s;
}
