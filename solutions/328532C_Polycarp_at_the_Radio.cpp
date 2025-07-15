// Problem: Polycarp at the Radio
// URL: https://codeforces.com/gym/328532/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[2100], cnt[2100], b[2100], sum[2100];


int main(){
    scanf("%d%d", &n, &m);
    int r=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if(a[i]<=m) b[a[i]]++;
        else r++;
    }
    int tot=n/m;
    int t=1, ans=0;
    for(int i=1; i<=n; i++){
        if(a[i]<=m && cnt[a[i]]<tot){
            cnt[a[i]]++;
            continue;
        }
        while(t<=m && b[t]>=tot) t++;
        if(t>m) break;
        a[i]=t; ans++; b[t]++; cnt[t]++;
    }
    printf("%d %d\n", tot, ans);
    for(int i=1; i<=n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}