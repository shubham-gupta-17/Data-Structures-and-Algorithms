#include <iostream>
using namespace std;
void update(int &z)
{
    z++;  // pass by reference using reference variables
	  // here x,y,z are having memory block we are not reassigning it rather we are just adding more variables to the block
}
int main() {
    int x=10;
    int &y=x;
    y +=1;
    cout<<y<<","<<x<<endl;
    update(x);
    update(y);
    cout<<y<<","<<x;
}

