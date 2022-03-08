// Problem: Floor Number
// URL: https://codeforces.com/gym/299852/problem/D
// Rating: 800
// Tags: none (gym/team contest)
// Language: GNU C11
#include <stdio.h>
void solve(void);

void solve(void)
{
    int n, x, count=0;
    scanf("%d%d",&n,&x);
    for(;n>2;n-=x,count++);
    printf("%d\n",count+1);
}




int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
