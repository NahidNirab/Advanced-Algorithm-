#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int row,col;
     cout<<"Enter Row and Column of the matrix\n";
     cout<<"enter Row= ";
     cin>>row;
     cout<<"enter column= ";
     cin>>col;
     int matrix[row][col];
     for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                {
                    if(i==0 || j==0)
                            {
                                matrix[i][j]=1;
                            }
                    else
                        {
                            matrix[i][j]=matrix[i-1][j]+matrix[i][j-1];
                        }
                }
        }
     for(int i=0;i<row;i++)
         {
            for(int j=0;j<col;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
     cout<<"\nThe possible Ways to reach there is = "<<matrix[row-1][col-1];
     return 0;
}
