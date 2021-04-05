// Problem: Increase and Copy
// URL: https://codeforces.com/gym/299852/problem/B
// Rating: 1100
// Tags: none (gym/team contest)
// Language: GNU C11
#include <stdio.h>
#include <math.h>
void solve(void);

void solve(void)
{
    int n, i=2, j, step;
    scanf("%d",&n);
    step=n-1;
    if (n<1000)
    {
       for(;i<=n;i++)
       {
           j=n/i;
           if(n%i==0)
            j--;
           if(step>i+j-1)
            step=i+j-1;
       }
    }
    else
    {
        for (i=sqrt(n)-10;i<=sqrt(n)+10;i++)
        {
            j=n/i;
            if(n%i==0)
             j--;
            if(step>i+j-1)
             step=i+j-1;
        }
    }
    printf("%d\n", step);
}


int main()
{
    int t;
    scanf("%d", &t);
    for (;t>0;t--)
        solve();
    return 0;
}
