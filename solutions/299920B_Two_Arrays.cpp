// Problem: Two Arrays
// URL: https://codeforces.com/gym/299920/problem/B
// Rating: 1100
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
#include <string.h>
#define N 110000
int n, i, T, a[N];
int *b[N];

void solve(void)
{
    int j=0;
    scanf("%d", &n);scanf("%d", &T);
    memset(a, 0, N); memset(b, 0, N);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i]<T/2)
            a[i]=0;
        else if (a[i]>T/2)
            a[i]=1;
        else if (T%2==1 && a[i]==T/2)
            a[i]=0;
        else
        {   j+=1; b[j]=&a[i];}
    }
    for (i=1; i<=j/2; i++)
        *b[i]=0;
    for (i=j/2+1; i<=j; i++)
        *b[i]=1;
    for(i=0; i<n; i++)
    printf("%d ", a[i]); printf("\n");
}


int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}

