/*
Name: Ritom Gupta
Class: S.Y B.Tech CSE-D
Roll: 203460
Subject: DS-II
*/
//#include<stack>
#include<string>
#include<iostream>
using namespace std;

class Node
{
  string word,meaning;
  Node *left,*right;
  friend class DictionaryBST;

public:
  Node()
  {
    word="";meaning="";
    left=NULL;
    right=NULL;
  }
};

class DictionaryBST
{
public:
    Node* root;

    DictionaryBST()
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
          cout<<"\nEnter word:";
          cin>>root->word;
          cin.ignore();
          cout<<"\nEnter meaning:";
          getline(cin,root->meaning);

          root->left=root->right=NULL;
        }
        else
        {
          Node* temp=root;
          int flag=0;
          Node* curr=new Node();
          cout<<"\nEnter word:";
          cin>>curr->word;
          cin.ignore();
          cout<<"\nEnter meaning:";
          getline(cin,curr->meaning);

          curr->left=curr->right=NULL;

          while(flag!=1)
          {
            if((curr->word).compare(temp->word) < 0)
            {
              if(temp->left==NULL)
              {
                temp->left=curr;flag=1;
              }
              else
                temp=temp->left;
            }

            else if ((curr->word).compare(temp->word) > 0)
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
              cout<<"Word exists!";
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
      char ch;string wordy="",meaningy="";
      do {
        cout<<"\nEnter word:";
        cin>>wordy;
        cin.ignore();
        cout<<"\nEnter meaning:";
        getline(cin,meaningy);
        //Node* temp=create_tree_rec_2(root,num);
        root=create_tree_rec_2(root,wordy,meaningy);
        cout<<"Continue? Y | N";
        cin>>ch;
      } while(ch=='Y');
      return root;
    }
    Node* create_tree_rec_2(Node* root,string wordy,string meaningy)
    {
      if(root==NULL)
      {
        Node* current=new Node();
        current->word=wordy;
        current->meaning=meaningy;
        current->left=current->right=NULL;
        return current;
      }
      else
      {
        if((wordy).compare(root->word) < 0)
        {
          Node* curr=new Node();
          curr->word=wordy;
          curr->meaning=meaningy;
          curr->left=curr->right=NULL;
          if(root->left==NULL)
          {root->left=curr;return root; }
          root->left=create_tree_rec_2(root->left,wordy,meaningy);
        }

        else if(wordy.compare(root->word) > 0)
        {
          Node* curr=new Node();
          curr->word=wordy;
          curr->meaning=meaningy;

          curr->left=curr->right=NULL;
          if(root->right==NULL)
          {root->right=curr;return root;}

          root->right=create_tree_rec_2(root->right,wordy,meaningy);
        }
        else
        {
          cout<<wordy<<" already exists in dictionary."<<endl;
        }
        return root;

      }
    }

    Node* delete_word(Node* root,string wordy)
    {
      Node* current=search_word(root,wordy);
      Node* parent=NULL;
      if(current==root)
      {
        if(current->right==NULL && current->left!=NULL)
        {
          root=root->left;current->right=current->left=NULL;
          delete current;
        }
        else if(current->left==NULL && current->right!=NULL)
        {
          root=root->right;
          delete current;
        }
        else if(current->left!=NULL && current->right!=NULL)
        {
          root=root->right;
          Node* temp=current->left;
          Node* s=root;
          while(s->left!=NULL)
            s=s->left;
          s->left=temp;
          current->left=current->right=NULL;
          delete current;

        }
        else
          {delete current;root=NULL;}
      }
      else if(current->left==NULL && current->right!=NULL)
      {
          if(current==parent->right)
            parent->right=current->right;
          else
            parent->left=current->right;

          current->left=current->right=NULL;
          delete current;
      }
      else if(current->left!=NULL && current->right==NULL)
      {
        if(current==parent->left)
          parent->left=current->left;
        else
          parent->right=current->left;
        current->left=current->right=NULL;
        delete current;
      }
      else if(current->left==NULL && current->right==NULL)
      {
        if(current==parent->left)
          parent->left=NULL;
        else
          parent->right=NULL;
        delete current;
      }
      return root;

    }
    Node* search_word(Node* root,string wordy)
    {
      if(root!=NULL)
      {
        if(wordy.compare(root->word)==0)
        {
          return root;
        }
        else if(wordy.compare(root->word)<0)
        {
          return search_word(root->left,wordy);
        }
        else
          return search_word(root->right,wordy);
      }
    }
    void preorder_traversal(Node* root)
    {
      if(root!=NULL)
      {
        cout<<"Word:"<<root->word<<", Meaning:"<<root->meaning<<endl;
        preorder_traversal(root->left);
        preorder_traversal(root->right);
      }
    }


    void inorder_traversal(Node* root)
    {
      if(root!=NULL)
      {
        inorder_traversal(root->left);
        cout<<"Word:"<<root->word<<", Meaning:"<<root->meaning<<endl;
        inorder_traversal(root->right);
      }
    }
    void postorder_traversal(Node* root)
    {
      if(root!=NULL)
      {
        preorder_traversal(root->left);
        preorder_traversal(root->right);
        cout<<"Word:"<<root->word<<", Meaning:"<<root->meaning<<endl;
      }
    }

    void erase_tree(Node* root)
    {
      if(root==NULL)return;
      erase_tree(root->left);
      erase_tree(root->right);
      cout<<"Deleting "<<root->word<<endl;
      delete root;
    }

};
int main()
{
  DictionaryBST* b=new DictionaryBST();
  int num;
  string word="",meaning="";
  //stack <int> s;


  int choice;
  do {
    cout<<"\n___________________________________";
    cout<<"\n0. Exit\n1. Create Dictionary (Non Recursive)\n2. Create Dictionary (Recursive) (Whacko)\n3. Insert word in dictionary\n4. Display Preorder (Recursive)\n5. Display Inorder (Recursive)\n6. Display Postorder (Recursive)\n7. Delete a word\n8. Erase tree (Recursive)\n"<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:b->root=b->create_tree_NR(b->root);
             break;

      case 2:b->root=b->create_recursively(b->root);
             break;

      case 3:
            cout<<"\nEnter word:";
            cin>>word;
            cin.ignore();
            cout<<"\nEnter meaning:";
            getline(cin,meaning);
            b->root=b->create_tree_rec_2(b->root,word,meaning);
            break;

      case 4:b->preorder_traversal(b->root);
             break;

      case 5:b->inorder_traversal(b->root);
             break;

      case 6:b->postorder_traversal(b->root);
             break;

      case 7:cout<<"\nEnter word:";
             cin>>word;
             b->root=b->delete_word(b->root,word);
             break;

      case 8:b->erase_tree(b->root);
            b->root=NULL;
            break;
    }
  } while(choice!=0);

  return 0;
}
