#include <bits/stdc++.h>
#include <string.h>
using namespace std;

void LPS_table(char pat[], int M, int lps[])
{

    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
        {
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    cout<<"\nPLS Table = ";
    for(int i=0;i<M;i++)
    {
        cout<<lps[i]<<" ";
    }
}

void KMP_patten_Search(char pat[], char txt[],int N,int M)
{
    int lps[M];
    LPS_table(pat, M, lps);
    int i = 0;
    int j = 0;
    while (i < N)
        {
            if (pat[j] == txt[i])
            {
                j++;
                i++;
                if(j == M)
                {
                    cout<<"\nFound pattern at index = "<<i-j;
                    j = lps[j - 1];
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i = i + 1;
                }
            }
        }
}

int main()
{

    char text[100];
    char patten[100];
    cout<<"Input your text array = ";
    cin.get (text,100);
    cout<<"\nInput your patten array = ";
    cin>>patten;
    int t_size = strlen(text);
    int p_size = strlen(patten);
    cout<<"\nThe size of your text array is = "<<t_size;
    cout<<"\nThe size of your patten array is = "<<p_size;
    KMP_patten_Search(patten, text, t_size, p_size);
    return 0;
}
