//./a.out < input_opplexico.txt for DFT
//./a.out < input_lexico.txt for BFT
#include<iostream>
#include<string>
#include<queue>
#include<stack>
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
  void DFS_NonRecur(GNode* start)
  {//to maintain alphabetic order in choosing neighbour, input has bigger to smaller lexico-order
    stack <GNode*> s;

    int visited[noofvertices];
    for(int i=0;i<noofvertices;i++)
    {
      visited[i]=0;
    }

    s.push(start);
  //  visited[get_vertexID(start)]=1;
    while(!s.empty())
    {
      start=s.top();s.pop();
      int id=get_vertexID(start);
      visited[id]=1;
      cout<<"\n"<<start->name<<",";
      int i=0;
      for(GNode* temp=head[get_vertexID(start)];temp!=NULL;temp=temp->next)
      {

        if(!visited[get_vertexID(temp)])
        {
          //cout<<"("<<temp->name<<")";
          visited[get_vertexID(temp)]=1;
          s.push(temp);
        }
        i++;
      }
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
    do
    {
      start=q.front();q.pop();
      int id=get_vertexID(start);
      visited[id]=1;
      cout<<start->name<<",";
      int i=0;
      for(GNode* temp=head[get_vertexID(start)];temp!=NULL;temp=temp->next)
      {
        if(!visited[get_vertexID(temp)])
        {
          visited[get_vertexID(temp)]=1;
          q.push(temp);
        }
        i++;
      }
    }while(!q.empty());
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
  //g->normal_display();
  cout<<"1. Depth First Traversal Recursive\t2. Depth First Traversal Non-Recursive\t3. Breadth First Traversal\n";
  int ch;GNode* start=new GNode();
  cin>>ch;
  switch(ch)
  {
    case 1: cout<<"Enter starting vertex:";
            cin>>start->name;
            if(g->search_adjList(start)==true)
              g->DFS_Recur(g->head[g->get_vertexID(start)]);
            else
              cout<<"Vertex does not exist";
            //break;

    case 2: cout<<"Enter starting vertex:";
            cin>>start->name;
            if(g->search_adjList(start)==true)
              g->DFS_NonRecur(g->head[g->get_vertexID(start)]);
            else
              cout<<"Vertex does not exist";
            //break;


    case 3: cout<<"Enter starting vertex:";
            cin>>start->name;
            if(g->search_adjList(start)==true)
              g->BFS_display(g->head[g->get_vertexID(start)]);
            else
              cout<<"Vertex does not exist";
            break;
  }
  cout<<endl;

}
