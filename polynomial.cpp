#include<iostream>
using namespace std

class Node
{
  int exp;
  double coeff;
  Node* next;


public:
  Node()
  {
    exp=0;
    coeff=0.0;
    next=NULL;
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
        Node* nn=new Node();
        cout<<"Enter coefficient:";
        cin>>nn->coeff;
        cout<<"Enter exponent:";
        cin>>nn->exp;
        cout<<"------------\n";
        H->next=nn;
        nn->next=NULL;
    }
  }

}
int main()
{
  Polynomial p1=new Polynomial();

  p1.

  return 0;
}
