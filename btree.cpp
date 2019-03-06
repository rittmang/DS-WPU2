#include<iostream>
using namespace std;

class Node
{
  int data;
  Node* left,right;
  friend class BinaryTree;

public:
  Node()
  {
    data=-sizeof(int);
    left=NULL;
    right=NULL;
  }
};

class BinaryTree
{
    Node* root;
    BinaryTree()
    {
      root=NULL;
    }
    void create_tree_rec(Node* root)
    {
      char ch;
      cout<<"\nL or R of "<<root->data<<"?";
      cin>>ch;
      if(ch=='L')
      {
        Node* curr=new Node();
        cout<<"\nEnter data:";
        cin>>curr->data;
        
      }
    }
}
