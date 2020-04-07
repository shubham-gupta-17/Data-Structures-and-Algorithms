#include<bits/stdc++.h>
using namespace std;
class data{

    private:
    int salary=1000;

    public:
    int number;
    char name[100];
    int salary2;

    void start()
    {
        cout<<" this is our code";

    }

    void setdata(int p){
       salary2=salary;
       salary=p;
       }

    int getdata(int n)
    {   if(n>10)
        return salary;
        else return salary2;
    }
};

int main()
{
    data d;
    d.number=5;
    char a[100]="shubham";
  /*  d.name[0]='s';
     d.name[1]='h';
      d.name[2]='u';
       d.name[3]='b';
       d.name[4]='\0';
*/
    strcpy(d.name,a);
cout<<d.name<<endl;
    d.start();

    cout<<sizeof(d)<<endl<<sizeof(data)<<endl;

   // d.setdata(100);
    cout<<endl<<d.getdata(5)<<endl;

    cout<<d.salary2;
    d.salary2=2000;
    cout<<endl<<d.salary2;


    return 0;
}
