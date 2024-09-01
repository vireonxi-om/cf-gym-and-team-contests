// Problem: Fight Against Traffic
// URL: https://codeforces.com/gym/316836/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, s, t, l[1100], cnts[1100], sums[1100], cntt[1100];
vector<int> g[1100];

int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v;
    for(int i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int lt;
    queue<int> a;
    a.push(s);
    l[s]=1; cnts[1]++;
    while(!a.empty()){
        int now=a.front();
        a.pop();
        for(auto x:g[now]){
            if(l[x]==0){
                l[x]=l[now]+1;
                cnts[l[x]]++;
                a.push(x);
            }
        }
    }
    int len=l[t];
    sums[1]=cnts[1];
    for(int j=2; j<=len; j++){
        sums[j]=sums[j-1]+cnts[j];
    }
    for(int i=1; i<=n; i++) l[i]=0;
    queue<int> b;
    b.push(t);
    l[t]=1; cntt[1]++;
    while(!b.empty()){
        int now=b.front();
        b.pop();
        for(auto x:g[now]){
            if(l[x]==0){
                l[x]=l[now]+1;
                cntt[l[x]]++;
                b.push(x);
            }
        }
    }
    int ans=0;
    for(int i=1; i<=len-2; i++){
        ans+=cntt[i]*sums[len-i-1];
    }
    ans=n*(n-1)/2-ans; ans-=m;
    printf("%d\n", ans);
}
