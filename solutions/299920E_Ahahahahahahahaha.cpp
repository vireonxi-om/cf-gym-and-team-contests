// Problem: Ahahahahahahahaha
// URL: https://codeforces.com/gym/299920/problem/E
// Rating: 1100
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
#include <string.h>
int n, i, j, x, y, z, a[1100];
void solve(void)
{
    memset(a,0,1100);
    scanf("%d",&n);
    for(i=1; i<=n/3; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if(x==y)
        {   a[2*i-1]=x; a[2*i]=y; }
        else if(x==z)
        {   a[2*i-1]=x; a[2*i]=z; }
        else
        {   a[2*i-1]=y; a[2*i]=z; }
    }
    i--; j=2*i;
    if(n%3==1)
    {
        scanf("%d", &x);
        if(x==0)
        {   a[2*i+1]=0; j+=1;}
    }
    if(n%3==2)
    {
        scanf("%d %d", &x, &y);
        if(x==y)
        {   a[2*i+1]=x; a[2*i+2]=x; j+=2;}
        else
        {   a[2*i+1]=0; j+=1;}
    }
    printf("%d\n", j);
    for(i=1; i<=j; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
