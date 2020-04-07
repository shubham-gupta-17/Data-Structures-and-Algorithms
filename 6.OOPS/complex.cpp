#include<bits/stdc++.h>
using namespace std;
class complex_number{
    
    public:
    int real ;
    int imaginary;

    complex_number()
    {

    }

    complex_number(int r,int l):real(r),imaginary(l){};

    void setreal(int r)
    {
        real=r;
    }
    void setimaginary(int i)
    {
        imaginary=i;
    }
    int getreal() const{
        return real;
    }
    int getimag() const{
        return imaginary;
    }

    void print() const
    {
        if(imaginary>0)
        cout<<real<<" + "<<imaginary<<"i"<<endl;
        else if(imaginary==0)
        cout<<real<<endl;
        else 
        cout<<real<<imaginary<<"i"<<endl;
    }
    void add(const complex_number &x,const complex_number &y)
    {
        real=x.real + y.real;
        imaginary =x.imaginary + y.imaginary;
    }
     void operator+(const complex_number &x)  //overloading + (binary)operator
    {
        real+=x.real;
        imaginary +=x.imaginary;
    }

    void operator!()
    {
        imaginary *=-1;
    }

    int operator[] (string s)
    {
        if(s=="real")
        return real;

        else
        return imaginary;
        
    }
};
istream &operator>>(istream &input,complex_number&x)
{
    int r,l;
    input>>r>>l;
    x.setreal(r);
    x.setimaginary(l);
    return input;

}
ostream& operator<<(ostream &output,complex_number &x)
{
    x.print();
    return output;
}
int main()
{
    complex_number c(5,3);
    complex_number d(4,5);
    complex_number e;
    e.setreal(5);
    d.setreal(5);
    c.print();
    d.print();
    e.print();

    //c.add(d);//it will add c and d and will update result in c;
    c.print();

     c+d;    //operator overloading and result is stored in c while d acts as paramter
    c.print();
    //we can not do c+d as both are objects not variables so we have to do operator overloading
    !c;
    c.print();

    complex_number f;
    f.add(c,d); //adding two numbers and storing there sum in third object
    f.print();
    cout<<f["real"];

    int r,l;
    cin>>r>>l;
    complex_number g(r,l);
    g.print();

    complex_number a;
    cin>>a;
    cout<<a;
    
    return 0;

}