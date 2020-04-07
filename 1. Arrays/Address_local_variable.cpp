#include<iostream>
using namespace std;
int x=10;
int *point()
{
//int x=10;
cout<<&x<<endl<<x<<endl;

return &x;     /// we should never return the address of local variable because when this function
               /// will get executed the variable will get destroyed and will no longer exist so

}

int main()
{ //int x=10;
int *xptr=point();
cout<<xptr<<endl<<N*xptr;
                           /// here it will show any garbage value in >> gcc +5 , in less then that
				           /// it will show 0
return 0;
}
