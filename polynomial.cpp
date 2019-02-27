#include<iostream>
using namespace std

class Node
{
  int exp;
  double coeff;
  Node* left;
  Node* right;

public:
  Node()
  {
    exp=0;
    coeff=0.0;
    left=NULL;
    right=NULL;
  }
}
class Polynomial
{
  Node *H;
public:
  Polynomial()
  {
    H=new Node();
    H->coeff=-1;
  }
  void display()
  {

  }
  void create()
  {
    int n=0;
    cout<<"Enter number of nodes";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        
    }
  }

}
int main()
{


  return 0;
}
