/*
Name: Ritom Gupta
Class: S.Y B.Tech CSE-D
Roll: 203460
Subject: DS-II
*/

#include<stack>
#include<iostream>
using namespace std;

class Node
{
  int data;
  Node *left,*right;
  friend class BinarySearchTree;

public:
  Node()
  {
    data=-999;
    left=NULL;
    right=NULL;
  }
};

class BinarySearchTree
{
public:
    Node* root;

    BinarySearchTree()
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
            if(curr->data < temp->data)
            {
              if(temp->left==NULL)
              {
                temp->left=curr;flag=1;
              }
              else
                temp=temp->left;
            }

            else if (curr->data > temp->data)
            {
              if(temp->right==NULL)
              {
                temp->right=curr;flag=1;
              }
              else
                temp=temp->right;
            }
            else
            {
              cout<<"Cannot add in BST (Value already exists)!";
              flag=1;
            }
          }
          //root=temp;
          temp=root;
        }
        cout<<"Continue? Y | N\n";
        cin>>choice;

      } while(choice=='Y');

      return root;
    }
    Node* create_recursively(Node* root)
    {
      char ch;int num;
      do {
        cout<<"Enter data:";
        cin>>num;
        //Node* temp=create_tree_rec_2(root,num);
        root=create_tree_rec_2(root,num);
        cout<<"Continue? Y | N";
        cin>>ch;
      } while(ch=='Y');
      return root;
    }
    Node* create_tree_rec_2(Node* root,int key)
    {
      if(root==NULL)
      {
        Node* current=new Node();
        current->data=key;
        current->left=current->right=NULL;
        return current;
      }
      else
      {
        if(key < root->data)
        {
          Node* curr=new Node();
          curr->data=key;
          curr->left=curr->right=NULL;
          if(root->left==NULL)
          {root->left=curr;return root; }
          root->left=create_tree_rec_2(root->left,key);
        }

        else if(key > root->data)
        {
          Node* curr=new Node();
          curr->data=key;
          curr->left=curr->right=NULL;
          if(root->right==NULL)
          {root->right=curr;return root;}

          root->right=create_tree_rec_2(root->right,key);
        }
        else
        {
          cout<<"Cannot insert another "<<key<<endl;
        }
        return root;

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

    void erase_tree(Node* root)
    {
      if(root==NULL)return;
      erase_tree(root->left);
      erase_tree(root->right);
      cout<<"Deleting"<<root->data<<endl;
      delete root;
    }

};
int main()
{
  BinarySearchTree* b=new BinarySearchTree();
  int num;
  //stack <int> s;


  int choice;
  do {
    cout<<"\n___________________________________";
    cout<<"\n0. Exit\n1. Create Search Tree (Non Recursive)\n2. Create Search Tree (Recursive) (Whacko)\n3. Display Preorder (Recursive)\n4. Display Inorder (Recursive)\n5. Display Postorder (Recursive)\n6. Erase tree (Recursive)\n"<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:b->root=b->create_tree_NR(b->root);
             break;

      case 2:b->root=b->create_recursively(b->root);
             break;

      case 3:b->preorder_traversal(b->root);
             break;

      case 4:b->inorder_traversal(b->root);
             break;

      case 5:b->postorder_traversal(b->root);
             break;

      case 6:b->erase_tree(b->root);
            b->root=NULL;
            break;
    }
  } while(choice!=0);

  return 0;
}
