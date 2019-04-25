#include<iostream>
#include<string>
#define max 20
using namespace std;
class student
{
  int rollno;
  string name;
  char grade;
public:
  student()
  {
      rollno=-1;
      name="";
      grade='';
  }
};
class hashing
{
  student hash_table[max];
public:
  void display()
  {

  }
  void lin_probing_Repl()
  {

  }
  void lin_probing_noRepl()
  {
    student ob=new student();
    do{
       cout<<"Enter roll number, name, and grade:\n";
       cin>>ob.rollno;
       cin.ignore();
       getline(cin,ob.name);

       int loc = ob.rollno%max;

       if(hash_table[loc].rollno==-1)
        hash_table[loc]=ob;

       else
       {
         for(int i=loc+1;i!=loc;i=(i+1)%max)
         {
           if(hash_table[i].rollno==-1)
           {
             hash_table[i]=ob;
             break;
           }
           else
            flag=1;
         }
       }
       if(flag==1)
        cout<<"Hash full.";

    }
  }
};
