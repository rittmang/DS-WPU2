#define MAX 20
#include<iostream>
using namespace std;
class heap
{
  int marks[MAX];
  int n;

public:
  heap()
  {
    cout<<"Enter number of students:";
    cin>>n;
    marks[n+1];
    for(int i=0;i<n+1;i++)
      marks[i]=0;
  }

  void max_heap()
  {
    char ch;
    int j=n;
    int m,i=1;
    do {
      cout<<"Enter marks:";
      cin>>m;
      marks[i]=m;
      insert_max(i);
      i++;
      j--;
      //cout<<"Continue? Y | N: ";
      //cin>>ch;
    } while(j>=1);

    disp();
  }

  void insert_max(int i)
  {
    int elem=marks[i];

    while((i>1)&&(marks[i/2]<elem))
    {
      marks[i]=marks[i/2];
      i=i/2;
    }
    marks[i]=elem;
  }
  void min_heap()
  {
    char ch;
    int j=n;
    int m,i=1;
    do {
      cout<<"Enter marks:";
      cin>>m;
      marks[i]=m;
      insert_min(i);//heapify
      i++;
      j--;
      //cout<<"Continue? Y | N: ";
      //cin>>ch;
    } while(j>=1);

    disp();
  }
  void insert_min(int i)
  {
    int elem=marks[i];

    while((i>1)&&(marks[i/2]>elem))
    {
      marks[i]=marks[i/2];
      i=i/2;
    }
    marks[i]=elem;
  }
  void disp()
  {
    for(int i=1;i<=n;i++)
    {
      cout<<marks[i]<<"\t";
    }
    cout<<"\n";
  }
};
int main()
{
  heap* ob=new heap();
  //ob->max_heap();
  ob->min_heap();
  return 0;
}