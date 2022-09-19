#include<bits/stdc++.h>
using namespace std;
int getMax(int num1, int num2)
{
 if(num1<num2)
 {
 return num2;
 }
 else
 {
 return num1;
 }
}
int Max(int num1,int num2,int num3)
{
 if(num1>num2 && num1>num3)
 {
 return num1;
 }
 else if(num2>num1 && num2>num3)
 {
 return num2;
 }
 else if(num3>num2 && num3>num1)
 {
 return num3;
 }
}
int maximum_value_sell(int c, int r, int matrix[50][50])
{
 int mat[r][c];
 for(int i=0;i<r;i++)
 {
 for(int j=0;j<c;j++)
 {
 mat[i][j]=matrix[i][j];
 }
 }
 int j=0;
 while(j<c)
 {
 for(int i=0;i<r;i++)
 {
 if(i==0 && j==0)
 {
 continue;
 }
 else if(i!=0 && j==0)
 {
 continue;
 }
 else if(i==0 && j!=0)
 {
 mat[i][j] = mat[i][j] + getMax(mat[i][j-1],mat[i+1][j-1]);
 }
 else if(i==(r-1) && j!=0)
 {
 mat[i][j] = mat[i][j]+getMax(mat[i-1][j-1],mat[i][j-1]);
 }
 else
 {
 mat[i][j]=mat[i][j]+Max(mat[i-1][j-1],mat[i][j-1],mat[i+1][j-1]);
 }
 }
 j++;
 }
 int maximum=0;
 int f=c-1;
 for(int i=0;i<r;i++)
 {
 if(maximum<=mat[i][f])
 {
 maximum = mat[i][f];
 }
 }
 int sell;
 cout<<"sells are = ";
 for(int i=0;i<r;i++)
 {
 if(maximum==mat[i][f])
 {
 sell = i;
 cout<<"("<<i<<","<<f<<"),";
 }
 }
 cout<<endl<<endl;
 return sell;
}
int Gold_mine(int c, int r, int matrix[50][50])
{
 int mat[r][c];
 for(int i=0;i<r;i++)
 {
 for(int j=0;j<c;j++)
 {
 mat[i][j]=matrix[i][j];
 }
 }
 int j=0;
 while(j<c)
 {
 for(int i=0;i<r;i++)
 {
 if(i==0 && j==0)
 {
 continue;
 }
 else if(i!=0 && j==0)
 {
 continue;
 }
 else if(i==0 && j!=0)
 {
 mat[i][j] = mat[i][j] + getMax(mat[i][j-1],mat[i+1][j-1]);
 }
 else if(i==(r-1) && j!=0)
 {
 mat[i][j] = mat[i][j]+getMax(mat[i-1][j-1],mat[i][j-1]);
 }
 else
 {
 mat[i][j]=mat[i][j]+Max(mat[i-1][j-1],mat[i][j-1],mat[i+1][j-1]);
 }
 }
 j++;
 }
 cout<<"Gold mine table : "<<endl;
 for(int i=0;i<r;i++)
 {
 for(int j=0;j<c;j++)
 {
 cout<<mat[i][j]<<" ";
 }
 cout<<endl;
 }
 cout<<endl;
 int maximum=0;
 int f=c-1;
 for(int i=0;i<r;i++)
 {
 if(maximum<=mat[i][f])
 {
 maximum = mat[i][f];
 }
 }
 return maximum;
}
int main()
{
 int row,col;
 cout<<"Enter Row and Column of the matrix\n";
 cout<<"enter Row= ";
 cin>>row;
 cout<<"enter column= ";
 cin>>col;
 int matrix[50][50];
 cout<<"enter matrix: "<<endl;
 for(int i=0;i<row;i++)
 {
 for(int j=0;j<col;j++)
 {
 cout<<"inputArray["<<i<<"]["<<j<<"] = ";
 cin>>matrix[i][j];
 }
 cout<<endl;
 }
 cout<<"maximum gold found is = "<<Gold_mine(col, row, matrix)<<endl;
 cout<<"one of the sell that we return in main faction is = ("<<maximum_value_sell(col,
row, matrix)<<","<<row-1<<")"<<endl;
 return 0;
}
