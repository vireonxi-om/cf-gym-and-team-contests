// Problem: Symmetric Matrix
// URL: https://codeforces.com/gym/299852/problem/C
// Rating: 900
// Tags: none (gym/team contest)
// Language: GNU C11
#include <stdio.h>
void solve(void);

void solve(void)
{
    int m, n, count=0;
    scanf("%d%d", &n, &m);
    for(;n>0;n--)
    {   int a[2][2];
        scanf("%d%d%d%d", &a[0][0],&a[0][1],&a[1][0], &a[1][1]);
        if(a[0][1]==a[1][0])
            count=1;
    }
    if(m%2==1)
        printf("NO\n");
    else if(!count)
        printf("NO\n");
    else
        printf("YES\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}


