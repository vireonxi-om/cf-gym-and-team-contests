// Problem: Cube
// URL: https://codeforces.com/gym/103055/problem/C
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[10], y[10], z[10];
vector<pair<int, int>> t;

int dis(int a, int i){
    return (x[i]-x[a])*(x[i]-x[a])+(y[i]-y[a])*(y[i]-y[a])+(z[i]-z[a])*(z[i]-z[a]);
}

bool check(int a){
    t.clear();
    for(int i=1; i<=8; i++){
        if(i==a) continue;
        t.push_back(make_pair(dis(i, a), i));
    }
    sort(t.begin(), t.end());
    int l1=t[0].first, l2=t[3].first, l3=t[6].first;
    if(t[1].first!=l1 || t[2].first!=l1) return false;
    if(t[4].first!=l2 || t[5].first!=l2) return false;
    if(l3!=3*l1 || l2!=2*l1 || l1==0) return false;
    int l=dis(t[1].second, t[2].second);
    if(l!=dis(t[2].second, t[0].second) || l!=dis(t[1].second, t[0].second)) return false;
    if(l!=l2) return false;
    l=dis(t[3].second, t[4].second);
    if(l!=dis(t[5].second, t[4].second) || l!=dis(t[5].second, t[3].second) || l!=l2) return false;
    return true;
}


void solve(){
    bool can=true;
    for(int i=1; i<=8; i++) scanf("%d%d%d", &x[i], &y[i], &z[i]);
    for(int i=1; i<=8; i++){
        if(!can) break;
        can=check(i);
    }
    if(can) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
