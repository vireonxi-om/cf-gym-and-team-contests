// Problem: Digit Game
// URL: https://codeforces.com/gym/299852/problem/J
// Rating: 900
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
#include <string.h>
#define N 1100
int a[N], n, i;

void solve(void)
{
    memset(a,0,sizeof(a));
    scanf("%d", &n);
    getchar();
    for(i=1; i<=n; i++)
    {   scanf("%c", &a[i]);
        a[i]-=48;}
    int count;
    if(!(n%2))
    {
        count=1;
        for (i=2; i<=n; i+=2)
        {
            if (!(a[i]%2))
                count=2;
        }
    }
    else
    {
        count=2;
        for (i=1; i<=n; i+=2)
        {
            if (a[i]%2)
                count=1;
        }
    }
    printf("%d\n", count);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
