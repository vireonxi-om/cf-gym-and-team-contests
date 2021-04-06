// Problem: Portals
// URL: https://codeforces.com/gym/319991/problem/D
// Rating: 2100
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, k, a[5100], b[5100], c[5100], fa[5100], lt[5100];
vector<int> g[5100];
priority_queue<pair<int, int>> ans;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    bool can=true;
    for(int i=1; i<=n; i++){
        fa[i]=i;
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    if(k<a[1]) can=false;
    for(int i=1; i<=n; i++){
        k+=b[i];
        if(i!=n){ lt[i]=k-a[i+1];}
        else lt[i]=k;
        if(lt[i]<0) can=false;
    }
    int u, v;
    for(int i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    for(int i=n; i>=1; i--){
        for(auto x:g[i]){
            fa[x]=max(fa[x], i);
        }
        ans.push(make_pair(c[i], fa[i]));
    }
    int tot=0;
    while(!ans.empty()){
        auto x=ans.top();
        ans.pop();
        bool yes=true;
        for(int i=x.second; i<=n; i++){
            if(lt[i]<=0) yes=false;
        }
        if(!yes) continue;
        tot+=x.first;
        for(int i=x.second; i<=n; i++) lt[i]--;
    }
    if(can) printf("%d\n", tot);
    else printf("-1\n");
    return 0;
}