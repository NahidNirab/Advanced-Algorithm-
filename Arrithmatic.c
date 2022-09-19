#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define size 50
char stacks[size];
int top = -1;

bool isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}
void push(char arr[],int j)
{
    if (top==size-1)
    {
        cout<<"stack is full\n";
    }
    else
    {
        top++;
        stacks[top]= arr[j];
    }
}

void pop()
{
    if(isempty())
    {
        cout<<"stack is empty\n";
    }
    else
    {
        top--;
    }
}


void showtop()
{
    if (isempty())
    {
        cout<<"array is empty and top = "<<top;
    }
    else
    {
        cout<<"\ntop position is = "<<top<<"\nelement in top is = "<<stacks[top];
        cout<<endl;
    }
}


void showstack()
{
    if(isempty())
    {
        cout<<endl<<"stack is empty because in first we find a closing bracket";
    }
    else
    {
        cout<<"stack is = ";
        for(int i=0;i<=top;i++)
        {
            cout<<stacks[i];
        }
    }
    cout<<endl;
}

void check(char arr[], int n)
{
    for(int j=0;j<n;j++)
    {
        if(arr[j]=='(' || arr[j]=='{' || arr[j]=='[')
        {
              push(arr, j);
              showtop();
              showstack();
        }
        else if(arr[j]==')' || arr[j]=='}' || arr[j]==']')
        {
              if (isempty())
              {
                  goto L;
              }
              else
              {
                  if(stacks[top]=='('&&arr[j]==')')
                  {
                      pop();
                  }
                  else if(stacks[top]=='{'&&arr[j]=='}')
                  {
                      pop();
                  }
                  else if(stacks[top]=='['&&arr[j]==']')
                  {
                      pop();
                  }
                  else
                  {
                      cout<<"\nopening parenthesis is missing! for = "<<arr[j]<<endl;
                      showtop();
                      showstack();
                      goto L;
                  }
              }
        }
    }
L:    if (top==-1)
    {
        cout<<endl<<"Arithmetic Expression is valid"<<endl;
    }
    else
    {
         cout<<endl<<"Arithmetic Expression is not valid"<<endl;
         showstack();
    }
}

int main()
{
    int n;
    cout <<"size of your array is = ";
    cin>>n;
    cout<<endl;
    char arr[n];
    cout<<"input your Arithmetic Expression = ";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    check(arr,n);
    return 0;
}
