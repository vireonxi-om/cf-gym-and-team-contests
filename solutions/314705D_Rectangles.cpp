// Problem: Rectangles
// URL: https://codeforces.com/gym/314705/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
vector<pair<int, int>> x, y;

int main(){
    scanf("%d", &n);
    int l1=-2e9, r1=2e9, lpos, rpos, u1=2e9, d1=-2e9, upos, dpos;
    for(int i=1; i<=n; i++){
        int l, r, u, d;
        scanf("%d%d%d%d", &l, &d, &r, &u);
        x.push_back(make_pair(l, r));
        y.push_back(make_pair(d, u));
        if(l>=l1){ l1=l; lpos=i; }
        if(r<=r1){ r1=r; rpos=i; }
        if(d>=d1){ d1=d; dpos=i; }
        if(u<=u1){ u1=u; upos=i; }
    }
    bool can=false;
    int ansx, ansy;
    int l=-2e9, r=2e9, u=2e9, d=-2e9;
    for(int i=0; i<n; i++){
        if(i==lpos-1) continue;
        else{
            r=min(r, x[i].second); l=max(l, x[i].first);
            u=min(u, y[i].second); d=max(d, y[i].first);
        }
    }
    if(r>=l && u>=d){ can=true; ansx=l; ansy=d;}
    l=-2e9, r=2e9, u=2e9, d=-2e9;
    for(int i=0; i<n; i++){
        if(i==rpos-1) continue;
        else{
            r=min(r, x[i].second); l=max(l, x[i].first);
            u=min(u, y[i].second); d=max(d, y[i].first);
        }
    }
    if(r>=l && u>=d){ can=true; ansx=l; ansy=d;}
    l=-2e9, r=2e9, u=2e9, d=-2e9;
    for(int i=0; i<n; i++){
        if(i==upos-1) continue;
        else{
            r=min(r, x[i].second); l=max(l, x[i].first);
            u=min(u, y[i].second); d=max(d, y[i].first);
        }
    }
    if(r>=l && u>=d){ can=true; ansx=l; ansy=d;}
    l=-2e9, r=2e9, u=2e9, d=-2e9;
    for(int i=0; i<n; i++){
        if(i==dpos-1) continue;
        else{
            r=min(r, x[i].second); l=max(l, x[i].first);
            u=min(u, y[i].second); d=max(d, y[i].first);
        }
    }
    if(r>=l && u>=d){ can=true; ansx=l; ansy=d;}
    printf("%d %d\n", ansx, ansy);
    return 0;
}
