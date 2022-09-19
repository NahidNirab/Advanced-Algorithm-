#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int subset_sum_problem(int n, int givenSet[], int s)
{
 int table[s+1][n+1];
 for(int i=0;i<=s;i++)
 {
 for(int j=0;j<=n;j++)
 {
 if((i==0) && (j==0))
 {
 table[i][j] = 1;
 }
 else if ((i==0) && (j!=0))
 {
 table[i][j] = 0;
 }
 else if (givenSet[i-1]>j)
 {
 table[i][j] = table[i-1][j];
 }
 else
 {
 table[i][j] = (table[i-1][j]) || (table[i-1][j-givenSet[i-1]]);
 }
 }
 }
 cout<<"The Table:\n\n";
 for(int i=0;i<=s;i++)
 {
 for(int j=0;j<=n;j++)
 {
 cout<<table[i][j]<<" ";
 }
 cout<<endl<<endl;
 }
 if (table[s+1][n+1] == 1)
 cout<<"\nThere exists a subset of the given set.. whose sum number is "<<n;
 else
 cout<<"\nThere no subset exist of the given set.. whose sum number is "<<n;
}
int main()
{
 int x, sum;
 cout<<"input array size= ";
 cin>>x;
 int givenSet[x];
 cout<<"\n\nInput the array Set= ";
 for(int i=0;i<x;i++)
 {
 cin>>givenSet[i];
 }
 cout<<"\n\ninput the sum number= ";
 cin>>sum;
 cout<<"\n\nhere 1 stand for True and 0 stand for False\n\n";
 subset_sum_problem(sum, givenSet, x);
 return 0;
}
