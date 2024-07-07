// Problem: Cubes Sorting
// URL: https://codeforces.com/gym/299852/problem/G
// Rating: 900
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
int a[51000];
void solve(void)
{
    int n, result=0;
    scanf("%d", &n);
    for( int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        if(i>0 && a[i]>=a[i-1])
            result=1;
    }
    if(result)
        printf("YES\n");
    else
        printf("NO\n");
}


int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}

