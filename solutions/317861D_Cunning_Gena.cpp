// Problem: Cunning Gena
// URL: https://codeforces.com/gym/317861/problem/D
// Rating: 1900
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, ab[110], x[110];
ll b, ans[1100000];
set<pair<int, int>> f;

int main(){
    scanf("%d%d%lld", &n, &m, &b);
    int ki, num, t;
    for(int i=1; i<=n; i++){
        scanf("%d%d%d", &x[i], &ki, &num);
        f.insert(make_pair(ki, i));
        while(num--){
            scanf("%d", &t);
            ab[i]+=pow(2, t-1);
        }
    }
    int tot=pow(2, m);
    ll result=0;
    auto it=f.begin();
    while(it!=f.end()){
        int kn=(*it).first, cur=(*it).second;
        if(ans[ab[cur]]==0) ans[ab[cur]]=x[cur];
        else ans[ab[cur]]=min(ans[ab[cur]], (ll)x[cur]);
        for(int j=0; j<tot; j++){
            int now=j|ab[cur];
            if(now==j || ans[j]==0) continue;
            else{
                if(ans[now]==0) ans[now]=ans[j]+x[cur];
                else {
                    ans[now]=min(ans[now], ans[j]+x[cur]);
                }
            }
        }
        if(ans[tot-1]){
            if(result) result=min(result, ans[tot-1]+kn*b);
            else result=ans[tot-1]+kn*b;
        }
        it++;
    }
    if(result) printf("%lld\n", result);
    else printf("-1\n");
    return 0;
}
