// Problem: Array Cancellation
// URL: https://codeforces.com/gym/299920/problem/G
// Rating: 1000
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
#include <string.h>
long long a[110000], sum;
int n;

void solve(void)
{
    memset(a, 0, 110000); sum=0;
    scanf("%d", &n);
    for (int i=1; i<=n-1; i++)
    {
        scanf("%lld", &a[i]);
        if(a[i]>=0)
            sum+=a[i];
        else if(sum+a[i]>=0)
            sum+=a[i];
        else
            sum=0;
    }
    scanf("%lld", &a[n]);
    printf("%lld\n", sum+a[n]);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
