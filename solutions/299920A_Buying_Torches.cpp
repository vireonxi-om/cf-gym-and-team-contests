// Problem: Buying Torches
// URL: https://codeforces.com/gym/299920/problem/A
// Rating: 1000
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
int x, y;
long long i, k;

void solve(void)
{
    scanf("%d %d %lld", &x, &y, &k);
    i=(long long)(k*y+k+x-3)/(x-1);
    printf("%lld\n", i+k);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
