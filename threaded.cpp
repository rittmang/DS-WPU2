
#include<iostream>
using namespace std;
class Node
{
  char data;
  Node  *left,*right;
  int lbit,rbit;
  friend class ThreadedBT;

public:
  Node()
  {
    data=' ';
    left=NULL;right=NULL;
    lbit=1;rbit=1;
  }
};
class ThreadedBT
{
  Node* root,*head;
public:
  ThreadedBT()
  {
    root=NULL;
  }
  void create_TBT()
  {
    head=new Node();head->right=head;
    root=new Node();
    cout<<"Enter Root char data:";
    cin>>root->data;
    head->left=root;
    head->lbit=0;
    char choice='Y';


    root->left=root->right=head;

    do {
      int flag=0;
      Node* temp=root;
      Node* current=new Node();
      cout<<"Enter character:";
      cin>>current->data;
      current->left=current->right=NULL;

      while(flag==0)
      {
        char dir;
        cout<<temp->data<<"'s L | R ?:\t";
        cin>>dir;
        if(dir=='L')
        {
          if(temp->lbit==1)
          {
            current->left=temp->left;
            current->right=temp;
            temp->left=current;
            temp->lbit=0;
            flag=1;
          }
          else
            temp=temp->left;
        }
        else if(dir=='R')
        {
            if(temp->rbit==1)
            {
              current->left=temp;
              current->right=temp->right;
              temp->right=current;
              temp->rbit=0;
              flag=1;
            }
            else
              temp=temp->right;
        }
        //temp=root;
      }

      cout<<"Continue? Y | N:\t";
      cin>>choice;
    } while(choice=='Y');
  }
  void preorder_TBT()
  {
    Node* temp=head->left;
    while(temp!=head)
    {
      cout<<temp->data<<endl;
      while(temp->lbit!=1)
      {
        temp=temp->left;
        cout<<temp->data<<endl;
      }

      while(temp->rbit==1)
        temp=temp->right;
      if(temp->rbit==0)
        temp=temp->right;

      if(temp->right==head)
      {
        cout<<temp->data<<endl;
        break;
      }
    }
  }
  void inorder_TBT()
  {
    Node* temp=head->left;
  //  while(temp->lbit!=0)
    //  temp=temp->left;

    while(1)
    {
      temp=inorder_successor(temp);
      if(temp==head)break;
      //else
        cout<<temp->data<<endl;
    }
  }
  Node* inorder_successor(Node* temp)
  {
    Node* x=temp->right;
    if(temp->rbit==0)
    {
      while(x->lbit==0)
        x=x->left;
    }
    return x;
  }
};
int main()
{
  ThreadedBT* b=new ThreadedBT();
  b->create_TBT();
  cout<<"Preorder:\n";
  b->preorder_TBT();
  cout<<"Inorder:\n";
  b->inorder_TBT();



  return 0;
}
