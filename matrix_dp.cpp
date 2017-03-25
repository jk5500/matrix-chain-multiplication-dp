#include <stdio.h>
#include <iostream>
#include <limits.h>
using namespace std;
 



#define max 15

void print(int s[max][max],int i,int j)

{

   if(i==j)

      printf("A%d",i);

   else

   {

      printf("(");

      print(s,i,s[i][j]);

      printf(" x ");

      print(s,s[i][j]+1,j);

      printf(")");

   }

}
int main()
{
    int p[] = {20, 6, 50, 10, 3, 20, 25};
    int n = sizeof(p)/sizeof(p[0]);
 
 
  
    int m[max][max]={0};
    int s[max][max]={0};
 
    int i, j, k, L, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;
 
    // L is chain length.
    for (L=2; L<n; L++)
    {
        for (i=0; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<j; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j]=k;
                    }


            }
        }
    }

    cout<<"cost matrix"<<endl;

    for (int i=1;i<n;i++)
    {
        for (int j=1;j<n;j++)
        {
            cout<<m[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"s matrix "<<endl;

    for (int i=1;i<n;i++)
    {
        for (int j=1;j<n;j++)
        {
            cout<<s[i][j]<<",";

        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"arrangement of matrix"<<endl;
    print(s,1,n-1);

    cout<<endl;
    return 0;
 
 
}
 
