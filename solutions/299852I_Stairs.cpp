// Problem: Stairs
// URL: https://codeforces.com/gym/299852/problem/I
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
typedef long long LL;
LL n, total, sum;

LL num(int m)
{
    n=(1LL<<m)-1;
    return (n*n+n)/2;
}

void solve(void)
{
    int i;
    scanf("%lld", &total);
    sum=0;
    for(i=1;;i++)
    {
        sum+=num(i);
        if(sum>total)
            break;
    }
    printf("%d\n", i-1);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}

