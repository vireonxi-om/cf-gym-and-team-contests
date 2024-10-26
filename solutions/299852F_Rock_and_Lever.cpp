// Problem: Rock and Lever
// URL: https://codeforces.com/gym/299852/problem/F
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>

typedef long long LL;
const int N=110000;
int a[N],b[32];

void solve(int n)
{
    int i, j;
	LL count=0;
    memset(b,0,sizeof(b));
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        for(j=0;(1<<j)<=a[i]; j++);
        b[j]+=1;
    }
    //for(i=0;i<n;i++)
    //{
    //    printf("%d ",b[i]);
    //}
    for(i=1;i<=30;i++)
    {
        count+=(LL)b[i]*(b[i]-1)/2;
    }
    printf("%lld\n", count);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    for (;t>0;t--)
    {
        scanf("%d",&n);
        solve(n);
    }
    return 0;
}

