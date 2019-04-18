#include<iostream>
#include<string>
#include<queue>
using namespace std;

class GNode
{
public:
  string name;
  GNode* next;
  GNode()
  {
    name="";
    next=NULL;
  }
};
class Graph
{
public:
  GNode* head[20];
  int noofvertices;


public:
  void create_adjList()
  {
    cout<<"Enter number of users:\n";
    cin>>noofvertices;

    for(int i=0;i<noofvertices;i++)
    {
      head[i]=new GNode();
        cout<<"Enter Username:";
      cin>>head[i]->name;
      head[i]->next=NULL;
    }
    char ch;
    int i=0;
    while (i<noofvertices) {
      GNode* temp=head[i];
      do {
          cout<<"-----------------------------------\n";
          GNode* current=new GNode();
          cout<<"\n\tEnter Dost of "<<head[i]->name<<": ";
          cin>>current->name;
          if(search_adjList(current)==false)
            {
              cout<<"User does not exist. Duh.\n";
              goto label;
            }
          if(current->name.compare(head[i]->name)==0)
          {
            cout<<"One should be friends with oneself, but not here.\n";
            goto label;
          }
          if(search_indivList(head[i],current)==true)
          {
            cout<<"Kitni baar dost banaega?\n";
            goto label;
          }
          temp->next=current;
          current->next=NULL;
          //current->next=temp;
          temp=current;

  label:cout<<"Continue? Y : N\n";
        cin>>ch;
      } while(ch=='Y');

      i++;
    }
  }
  void normal_display()
  {
    for(int i=0;i<noofvertices;i++)
    {
      GNode* current=head[i];
      while(current!=NULL)
      {
        cout<<current->name<<"\t";
        current=current->next;
      }
      cout<<endl;
    }
  }

  void DFS_Recur(GNode* start)
  {
    int index=get_vertexID(start);
    int visited[noofvertices];
    for(int i=0;i<noofvertices;i++)
    {
      visited[i]=0;
    }
    DFS_Recur_Assoc(index,visited);
  }
  void DFS_Recur_Assoc(int index,int visited[])
  {
    cout<<head[index]->name<<"\n";
    visited[index]=1;
    GNode* temp=head[index];
    while(temp!=NULL)
    {
      int loc=get_vertexID(temp);
      if(visited[loc]==0)
        DFS_Recur_Assoc(get_vertexID(temp),visited);
      temp=temp->next;
    }
  }
  void BFS_display(GNode* start)
  {
    queue <GNode*> q;

    int visited[noofvertices];
    for(int i=0;i<noofvertices;i++)
    {
      visited[i]=0;
    }

    q.push(start);
    while(!q.empty())
    {
      start=q.front();q.pop();
      int id=get_vertexID(start);
      visited[id]=1;
      cout<<start->name<<",";
      int i=0;
      for(GNode* temp=head[i];temp!=NULL;temp=temp->next)
      {
        if(!visited[i])
        {
          visited[i]=1;
          q.push(temp);
        }
        i++;
      }
    }
  }
  int get_vertexID(GNode* temp)
  {

    for(int i=0;i<noofvertices;i++)
    {
        if(head[i]->name.compare(temp->name)==0)
          return i;
    }
    return -1;

  }
  bool search_adjList(GNode* temp)
  {
    for(int i=0;i<noofvertices;i++)
      if(temp->name.compare(head[i]->name)==0)
        return true;
    return false;
  }
  bool search_indivList(GNode* user,GNode* dost)
  {
    GNode* current=user;
    while(current!=NULL)
    {
        if(current->name.compare(dost->name)==0)
          return true;
        current=current->next;
    }
    return false;
  }
};
int main()
{
  Graph* g=new Graph();
  g->create_adjList();
  g->normal_display();
  g->BFS_display(g->head[0]);
  cout<<endl;
  g->DFS_Recur(g->head[0]);

}
