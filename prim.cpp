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
      if(mat[i][j]==INT_MAX){
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
  }
  void display_adjMat()
  {
    cout<<"\nGraph Display:\n";
    for(int i=0;i<noofvertices;i++)
    {
      for(int j=0;j<noofvertices;j++)
      {
        if(mat[i][j]!=INT_MAX)
          cout<<mat[i][j]<<"\t";
        else
          cout<<"*\t";
      }
      cout<<endl;
    }
  }
  void prim()
  {
    int stv;
    cout<<"Enter starting vertex:";
    cin>>stv;
    int mincost=0;
    int t[noofvertices][2];
    int nearest[noofvertices];
    nearest[stv]=-1;

    for(int i=0;i<noofvertices;i++)
    {
      if(i!=stv)
        nearest[i]=stv;
    }
    int r=0;
    int min;
    for(int i=1;i<noofvertices;i++)
    {
      min=INT_MAX;
      int j;
      for(int k=0;k<noofvertices;k++)
      {

        if(nearest[k]!=-1 && mat[k][nearest[k]]<min)
        {
          j=k;
          min=mat[k][nearest[k]];
        }
      }
      t[r][0]=j;
      t[r][1]=nearest[j];
      r=r+1;
      mincost=mincost+mat[j][nearest[j]];
      nearest[j]=-1;
      for(int k=0;k<noofvertices;k++)
      {
        if(nearest[k]!=-1 && mat[k][nearest[k]] > mat[k][j])
          nearest[k]=j;
      }
    }
    cout<<"MST Value:"<<mincost<<"\n";
  }
};
int main()
{
  GraphPrim g;
  g.create_adjMat();
  g.display_adjMat();
  g.prim();
  return 0;
}
