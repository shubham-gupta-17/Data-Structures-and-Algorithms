#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n;
  cin>>n;
 cin>>s;
 string a;
 int number=0,c=0,j;
 // char *a = new char[s.length()];
 int b[9]={2,3,5,7,11,13,17,19,23};
   for(int i=0;i<s.length();i++)
   {     a="\0";  ///to clear the string
      for( j=i;j<s.length();j++)
      {
        a +=s[j];    ///copy from array to string
       // cout<<a<<endl;
       number=0;
         for(int k=0;k<a.length();k++)
         {
            number = number*10 + a[k]-'0';   ///convert string to integer
         }
        int c1=0;
         for(int l=0;l<9;)
         {
             if(number==0 || number==1 || number%b[l]==0)
              break;                                                    ///finding CB number

            else if(number%b[l]!=0 || number==b[l]){
               c1++;
               ;l++;}
         }
         if(c1==9) {
          c++;
          cout<<c<<"  "<<number<<endl;
         // i=j+1;
          // break;

         }

      }

   }
   cout<<c;
}
