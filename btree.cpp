#include<iostream>
using namespace std;

class Node
{
  int data;
  Node *left,*right;
  friend class BinaryTree;

public:
  Node()
  {
    data=-999;
    left=NULL;
    right=NULL;
  }
};

class BinaryTree
{
public:
    Node* root;
    BinaryTree()
    {
      root=NULL;
      //root=new Node();
    }
    Node* create_tree_NR(Node* root)
    {
      char choice;
      do {

        if(root==NULL)
        {
          root=new Node();
          cout<<"\nEnter root data:";
          cin>>root->data;
          root->left=root->right=NULL;
        }
        else
        {
          Node* temp=root;
          int flag=0;
          Node* curr=new Node();
          cout<<"\nEnter data:";
          cin>>curr->data;
          curr->left=curr->right=NULL;

          while(flag!=1)
          {
            char ch;
            cout<<"\nEnter "<<temp->data<<"'s L/R:";
            cin>>ch;
            if(ch=='L')
            {
              if(temp->left==NULL)
              {
                temp->left=curr;flag=1;
              }
              else
                temp=temp->left;
            }

            else if (ch=='R')
            {
              if(temp->right==NULL)
              {
                temp->right=curr;flag=1;
              }
              else
                temp=temp->right;
            }
          }
          root=temp;
        }
        cout<<"Continue? Y | N\n";
        cin>>choice;
      } while(choice=='Y');

      return root;
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
        curr->left=curr->right=NULL;
        if(root->left==NULL)
          root->left=curr;

        create_tree_rec(root->left);
      }

      if(ch=='R')
      {
        Node* curr=new Node();
        cout<<"\nEnter data:";
        cin>>curr->data;
        curr->left=curr->right=NULL;
        if(root->right==NULL)
          root->right=curr;

        create_tree_rec(root->right);
      }

    }
    void preorder_traversal(Node* root)
    {
      if(root!=NULL)
      {
        cout<<root->data<<"\t";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
      }
    }
    void inorder_traversal(Node* root)
    {
      if(root!=NULL)
      {
        inorder_traversal(root->left);
        cout<<root->data<<"\t";
        inorder_traversal(root->right);
      }
    }
    void postorder_traversal(Node* root)
    {
      if(root!=NULL)
      {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout<<root->data<<"\t";

      }
    }
};
int main()
{
  BinaryTree* b=new BinaryTree();


  int choice;
  do {
    cout<<"\n___________________________________";
    cout<<"\n0. Exit\n1. Create Tree (Non Recursive)\n2. Display Preorder\n3. Display Inorder\n4. Display Postorder"<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:b->root=b->create_tree_NR(b->root);
             break;

      case 2:b->preorder_traversal(b->root);
            break;

      case 3:b->inorder_traversal(b->root);
            break;

      case 4:b->postorder_traversal(b->root);
            break;
    }
  } while(choice!=0);

  return 0;
}
