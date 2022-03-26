// Problem: Fence
// URL: https://codeforces.com/gym/299852/problem/E
// Rating: 800
// Tags: none (gym/team contest)
// Language: GNU C11
#include <stdio.h>
void solve(void);

void solve(void)
{
    int a, b, c, i;
    scanf("%d%d%d", &a, &b, &c);
    if (b>a)
    { i=b; b=a; a=i; }
    if (c>a)
    { i=c; c=a; a=i; }
    printf("%d\n", a);
}


int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
