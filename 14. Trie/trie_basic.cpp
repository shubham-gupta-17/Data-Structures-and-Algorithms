#include<iostream>
#include<vector>
using namespace std;
class Node{
  public :
  int word_end=0;
  vector<Node*> childs;

  Node()
  {
     childs.assign(26,NULL);
  }
};
int main()
{

}
