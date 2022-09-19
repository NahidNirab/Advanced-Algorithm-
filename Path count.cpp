#include<bits/stdc++.h>
using namespace std;
void coin_change(int a, int b, int c[])
{
     int dp_table[b+1][a+1];
     for(int i=0;i<=b;i++)
     {
        for(int j=0;j<=a;j++)
        {
            if((i==0) && (j==0))
            {
                dp_table[i][j] = 1;
            }
            else if ((i==0) && (j!=0))
            {
                dp_table[i][j] = 0;
            }
            else if (c[i-1]>j)
            {
                dp_table[i][j] = dp_table[i-1][j];
            }
            else
            {
                dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-c[i-1]];
            }
        }
     }
     cout <<endl<<"table :"<<endl;
     for(int i=0;i<=b;i++)
     {
        for(int j=0;j<=a;j++)
        {
            cout<<" "<<dp_table[i][j];
        }
     cout<<endl;
     }
     cout<<endl<<"Maximum count for "<<a<<" unit is = "<<dp_table[b][a];
     cout<<endl;
}
int main()
{
     cout<<"inter your unit number = ";
     int unit;
     cin>>unit;
     int coins[] = {1, 2, 3, 5};
     int size = sizeof(coins)/sizeof(int);
     coin_change(unit, size, coins);
     return 0;
}
