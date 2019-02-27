#include<iostream>
using namespace std;

class Node
{
  friend class Polynomial;
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
};
class Polynomial
{
  Node *H;
public:
  Polynomial()
  {
    H=new Node();
    H->coeff=-1;
    H->next=H;
  }
  void display()
  {
    Node* current=H;
    current=current->next;

    while(current!=H)
    {
      if(current->next!=H)
        cout<<current->coeff<<"X^"<<current->exp<<"+";

      else
        cout<<current->coeff<<"X^"<<current->exp;

      current=current->next;
    }
    cout<<"\n\n";
  }
  void create()
  {
    int n=0;
    cout<<"Enter number of nodes";
    cin>>n;
    Node* current=H;
    while(current->next!=H)
      current=current->next;

    for(int i=0;i<n;i++)
    {
        Node* nn=new Node();
        cout<<"Enter coefficient:";
        cin>>nn->coeff;
        cout<<"Enter exponent:";
        cin>>nn->exp;
        cout<<"------------\n";
        current->next=nn;
        nn->next=H;
        current=nn;
    }
  }

};
int main()
{
  Polynomial* p1=new Polynomial();

  p1->create();
  p1->display();

  return 0;
}
