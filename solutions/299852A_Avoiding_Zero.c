// Problem: Avoiding Zero
// URL: https://codeforces.com/gym/299852/problem/A
// Rating: 900
// Tags: none (gym/team contest)
// Language: GNU C11
#include <stdio.h>
void solve(int, int[], int[]);
int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d",&n);
        int a[n], b[n];
        solve(n, a, b);
    }
    return 0;
}

void solve(int n, int a[], int b[])
{
    int i, j, k, sum=0;
    for(i=0;i<=n-1;i++)
    {   scanf("%d",&a[i]);
        sum+=a[i];}
    if(sum==0)
        printf("NO\n");
    else
    {   printf("YES\n");
        if(sum>0)
        {
            for(i=0, j=0, k=n-1; i<=n-1; i++)
            {
                if (a[i]>0)
                {   b[j]=a[i]; j++;}
                else
                {   b[k]=a[i]; k--;}
            }
        }
        else
        {
            for(i=0, j=0, k=n-1; i<=n-1; i++)
            {
                if (a[i]<0)
                {   b[j]=a[i]; j++;}
                else
                {   b[k]=a[i]; k--;}
            }
        }
        for(i=0;i<=n-1;i++)
            printf("%d ", b[i]);
        printf("\n");
    }



}




