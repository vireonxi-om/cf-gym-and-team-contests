// Problem: Hotpot
// URL: https://codeforces.com/gym/103117/problem/B
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, m, cnt[110000], id[110000], t[110000], ans[110000];

void solve(){
    scanf("%d%d%d", &n, &k, &m);
    for(int i=1; i<=k; i++) cnt[i]=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &id[i]);
        cnt[id[i]]++;
        if(cnt[id[i]]%2) t[i]=1;
        else t[i]=2;
    }
    int tot=m/n, l=m%n;
    for(int i=1; i<=n; i++){
        if(cnt[id[i]]%2==0){
            if(t[i]==1) ans[i]=0;
            else{
                ans[i]=tot;
                if(i<=l) ans[i]++;
            }
        }
        else{
            if(tot%2==0){
                ans[i]=tot/2;
                if(i<=l && t[i]==2) ans[i]++;
            }
            else{
                ans[i]=tot/2;
                if(t[i]==2) ans[i]++;
                if(i<=l && t[i]==1) ans[i]++;
            }
        }
    }
    for(int i=1; i<=n; i++){
        printf("%d", ans[i]);
        if(i<n) printf(" ");
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


