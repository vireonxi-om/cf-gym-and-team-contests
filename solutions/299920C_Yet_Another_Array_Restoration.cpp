// Problem: Yet Another Array Restoration
// URL: https://codeforces.com/gym/299920/problem/C
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <stdio.h>
#include <string.h>
int n, x, y, i, j, a[55];

void solve(void)
{
    memset(a, 0, 55);
    scanf("%d%d%d", &n, &x, &y);
    if((y-x)%(n-1)==0)
    {
        a[0]=x;
        i=(y-x)/(n-1);
    }
    else
    {
        j=n;
        for(i=1;i<y-x;i++)
        {
            if((y-x)%i==0 && (n-1)*i>=(y-x))
                break;
        }
        j-=(y+i-1)/i;
        if(j<=0)
            a[0]=y-(n-1)*i;
        else
            a[0]=y+j*i-(n-1)*i;
    }
    for(j=0;j<n;j++)
    {
        printf("%d ", a[0]+j*i);
    }
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
