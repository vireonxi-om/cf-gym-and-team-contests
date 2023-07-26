// Problem: Sage's Birthday (hard version)
// URL: https://codeforces.com/gym/303728/problem/E
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, result;
int a[110000], b[110000];

int main(){
    scanf("%d", &n);
    result=0;
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for(int i=1, j=n; i<=n;){
        b[i]=a[j];
        i+=2; j--;
    }
    int j=1;
    for(int i=n-((n+1)%2)-1; i>=1;){
        b[i]=a[j];
        if(b[i]<b[i+1] && b[i]<b[i-1]) result++;
        i-=2;
        j++;
    }
    if(n%2==0) b[n]=a[j];
    printf("%d\n", result);
    for(int i=1; i<=n; i++) printf("%d ", b[i]);
    printf("\n");
    return 0;
}


