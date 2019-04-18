#define MAX 20
#include<iostream>
#include<string>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class GraphPrim
{
  int mat[MAX][MAX];
  int noofvertices;

public:
  GraphPrim()
  {
    cout<<"Enter number of offices:";
    cin>>noofvertices;
    mat[noofvertices][noofvertices];
    for(int i=0;i<noofvertices;i++)
    {
      for(int j=0;j<noofvertices;j++)
      {
        mat[i][j]=INT_MAX;
      }
    }
  }
  void create_adjMat()
  {
    for(int i=0;i<noofvertices;i++)
    {
      for(int j=0;j<noofvertices;j++)
      {
        cout<<"Is "<<i<<" a neighbour of "<<j<<"?";

        char ch;
        cin>>ch;

        if(ch=='Y'||ch=='y')
        {
          cout<<"\nEnter cost of path:";
          cin>>mat[i][j];
          mat[j][i]=mat[i][j];
        }
      }
    }
  }
  void display_adjMat()
  {
    cout<<"\nGraph Display:\n";
    for(int i=0;i<noofvertices;i++)
    {
      for(int j=0;j<noofvertices;j++)
      {
        cout<<mat[i][j]<<"\t";
      }
      cout<<endl;
    }
  }
};
int main()
{
  GraphPrim g;
  g.create_adjMat();
  g.display_adjMat();
  return 0;
}
