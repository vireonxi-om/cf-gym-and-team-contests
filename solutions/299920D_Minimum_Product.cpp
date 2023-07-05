// Problem: Minimum Product
// URL: https://codeforces.com/gym/299920/problem/D
// Rating: 1100
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
long long a, b, x, y, n, i, j, result;

void solve(void)
{
    scanf("%d%d%d%d%d", &a, &b, &x, &y, &n);
    if(a+b-x-y-n>=0)
    {
        if(a-x>=n)
            i=(a-n)*b;
        else
            i=x*(a+b-x-n);
        if(b-y>=n)
            j=a*(b-n);
        else
            j=(a+b-y-n)*y;
        if(i>j)
            result=j;
        else
            result=i;
    }
    else
        result=x*y;
    printf("%lld\n", result);
}


int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}

