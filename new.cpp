#include<bits/stdc++.h>
#include <iostream>
#include<algorithm>
using namespace std;

int sDivisor(int x)
{
  if(x%2==0)
  return 2;
  for(int i=3;i*i<=x;i+=2)
  {
    if(x%i==0)
    return i;
  }
  return x;
}
int sInteger(int* arr,int n)
{
  int gcd1=0;
  for(int i=0;i<n;i++)
  {
    gcd1=__gcd(gcd1,arr[i]);
  }
  return sDivisor(gcd1);

}
int main()
{
  int arr[]={2,4,8};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<sInteger(arr,n);
  return 0;
}
