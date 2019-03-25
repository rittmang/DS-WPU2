/*
Name: Ritom Gupta
Class: S.Y B.Tech CSE - Panel 2
Roll: 203460
Subject: DS-II
*/

#include<iostream>
#include<math.h>
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
    H->exp=-1;
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
  void insert(int exp1,double coeff1)
  {
    Node* current=H;
    Node* nn=new Node();
    nn->coeff=coeff1;
    nn->exp=exp1;

    while(current->next!=H && current->next->exp < nn->exp)
      {current=current->next;}



    Node *temp=current;
    current=current->next;
    temp->next=nn;
    nn->next=current;
}
  void evaluate()
  {
    Node* current=H;
    current=current->next;

    int x=0;
    cout<<"Enter value of X:";
    cin>>x;
    double sum;
    while(current!=H)
    {
      sum+=current->coeff*pow(x,current->exp);
      current=current->next;
    }
    cout<<"Result:"<<sum;
    cout<<"\n";

  }

 Polynomial* add(Polynomial *p2)
 {
  	Polynomial* p3=new Polynomial();

  	Node* current1=this->H;
  	current1=current1->next;

  	Node* current2=p2->H;
  	current2=current2->next;

  	while(current1 != this->H && current2 != p2->H)
  	{
      if(current1->exp < current2->exp)
  		{
  			p3->insert(current1->exp,current1->coeff);
  			current1=current1->next;
  		}
  		else if(current1->exp > current2->exp)//signs inverted < & >
  		{
  			p3->insert(current2->exp,current2->coeff);
  			current2=current2->next;
  		}
  		else
  		{
  			if((current1->coeff+current2->coeff)!=0)
  			{
  				p3->insert(current1->exp,current1->coeff+current2->coeff);
  				current1=current1->next;
  				current2=current2->next;
  			}
  		}

  	}
  	while(current1!=this->H)
  	{
  		p3->insert(current1->exp,current1->coeff);
  		current1=current1->next;
  	}
  	while(current2!=p2->H)
  	{
  		p3->insert(current2->exp,current2->coeff);
  		current2=current2->next;
  	}
  	return p3;

 }

 void create()
  {
    int n=0;
    cout<<"Enter number of nodes";
    cin>>n;

    //while(current->next!=H ||   )
      //current=current->next;

    for(int i=0;i<n;i++)
    {
        Node* current=H;
        Node* nn=new Node();
        cout<<"Enter coefficient:";
        cin>>nn->coeff;
        cout<<"Enter exponent:";
        cin>>nn->exp;
        cout<<"------------\n";

        while(current->next!=H && current->next->exp < nn->exp)
          {current=current->next;}

        Node *temp=current;
        current=current->next;
        temp->next=nn;
        nn->next=current;
    }
  }

};
int main()
{
  Polynomial* p1=new Polynomial();
  Polynomial* p2=new Polynomial();
  Polynomial* p3=new Polynomial();
  int nopoly,choice;

  do
  {
  	cout<<"\nChoose Polynomial(1-2):\n";
  	cin>>nopoly;
  	if(nopoly==0)break;

  	cout<<"******MENU*******\n1. Create Polynomial\n2. Display Polynomial\n3. Add Polynomial\n4. Evaluate Polynomial\n";
  	cin>>choice;

  	if(nopoly==1)
  	{
  		switch(choice)
  		{
  			case 1: p1->create();
  				break;

  			case 2: p1->display();
  				break;

  			case 3: p3=p1->add(p2);
  				p3->display();
  				break;

  			case 4: p1->evaluate();
  				break;
  		}
  	}
  	if(nopoly==2)
  	{
  		switch(choice)
  		{
  			case 1: p2->create();
  				break;

  			case 2: p2->display();
  				break;

  			case 3: p3=p2->add(p1);
  				p3->display();
  				break;

  			case 4: p2->evaluate();
  				break;
  		}
  	}

  }while(choice!=0);
  return 0;
}
