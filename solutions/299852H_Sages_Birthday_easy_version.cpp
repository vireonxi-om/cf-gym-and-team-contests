// Problem: Sage's Birthday (easy version)
// URL: https://codeforces.com/gym/299852/problem/H
// Rating: 1000
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
#define N 110000
int a[N], i;
int main()
{
    int n, j;
    scanf("%d", &n);
    for(i=0; i<N; i++)
            a[i]=0;
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(i=2;i<n;i+=2)
    {
        if(a[i]<a[i-1])
        {j=a[i];a[i]=a[i-1];a[i-1]=j;}
        if(a[i-2]<a[i-1])
        {j=a[i-2];a[i-2]=a[i-1];a[i-1]=j;}
    }
    printf("%d\n", (n+n%2)/2-1);
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


