// Problem: Interstellar battle
// URL: https://codeforces.com/gym/319427/problem/E
// Rating: 2200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, fa[110000], cnt[110000];
double p[110000], s[110000], result;
vector<int> g[110000];

void dfs(int a, int b){
    if(g[a].size()==1) return;
    for(auto x:g[a]){
        if(x==b) continue;
        cnt[a]++;
        fa[x]=a;
        s[a]+=p[x];
        dfs(x, a);
    }
    result+=p[a]*(cnt[a]-s[a]);
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lf", &p[i]);
    int u, v;
    for(int i=1; i<n; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(auto x:g[0]){
        cnt[0]++;
        s[0]+=p[x];
        fa[x]=0;
        dfs(x, 0);
    }
    result+=p[0]*(cnt[0]-s[0]);
    result+=(1-p[0]);
    int q, t;
    double val;
    scanf("%d", &q);
    while(q--){
        /*for(int i=0; i<n; i++) printf("%.5f ", s[i]);
        printf("\n");
        for(int i=0; i<n; i++) printf("%d ", fa[i]);
        printf("\n");
        printf("result: %.5f\n", result);*/
        scanf("%d%lf", &t, &val);
        if(t){ s[fa[t]]+=(val-p[t]); result-=p[fa[t]]*(val-p[t]);}
        else{ result-=(val-p[t]);}
        result+=(val-p[t])*(cnt[t]-s[t]);
        p[t]=val;
        printf("%.5f\n", result);
    }
    return 0;
}