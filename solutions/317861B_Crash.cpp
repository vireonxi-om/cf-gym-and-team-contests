// Problem: Crash
// URL: https://codeforces.com/gym/317861/problem/B
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110000];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=100000; i++) a[i]=-1;
    int x, k;
    bool can=true;
    for(int i=1; i<=n; i++){
        scanf("%d%d", &x, &k);
        if(x-a[k]>1) can=false;
        else a[k]=max(a[k], x);
    }
    if(can) printf("YES\n");
    else printf("NO\n");
    return 0;
}
