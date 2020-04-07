#include<iostream>
#include<cstring>
using namespace std;
int main()
{   // string tokenizer
  char a[]=",I am a bad , bad boy";
  char *ptr;
  ptr=strtok(a," ");
  while(ptr!=NULL)
/** NULL as a parameter signifies that we have to extract from the original string because if we pass (string a) again then it will again
start from the 1st index i.e. I and if NULL is passed then it will start from the index where it has left in the previous call**/
{
    cout<<ptr<<endl;
    ptr=strtok(NULL," ,");     ///it will terminate each element after it gets a spacebar and comma


}

   for(int i=0;i<sizeof(a);i++)    /// it will print each character one by one we can also use a[i]!='\0'
    cout<<a[i]<<endl;

    cout<<sizeof(a);   /// it already includes null character

}
