// Problem: Wall Game
// URL: https://codeforces.com/gym/103055/problem/G
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p[510000], cnt[510000];
map<pair<int, int>, int> g;
set<int> m;

int fi(int x){
    return p[x]==x? x: p[x]=fi(p[x]);
}


int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) p[i]=i;
    int t, x, y;
    for(int i=1; i<=n; i++){
        scanf("%d%d%d", &t, &x, &y);
        if(t==1){
            g[make_pair(x, y)]=i;
            m.clear();
            int tot=0, now=0;
            for(int a=x-1; a<=x+1; a+=2){
                auto id=make_pair(a, y);
                if(g.find(id)!=g.end()){
                    m.insert(fi(g[id]));
                    now++;
                }
            }
            for(int b=y-1; b<=y+1; b+=2){
                auto id=make_pair(x, b);
                if(g.find(id)!=g.end()){
                    m.insert(fi(g[id]));
                    now++;
                }
            }
            auto id=make_pair(x+1, y-1);
            if(g.find(id)!=g.end()) {
                m.insert(fi(g[id]));
                now++;
            }
            id=make_pair(x-1, y+1);
            if(g.find(id)!=g.end()) {
                m.insert(fi(g[id]));
                now++;
            }
            for(auto num:m){
                tot+=cnt[num];
                p[fi(num)]=i;
            }
            cnt[i]=6-2*now+tot;
        }
        if(t==2){
            auto id=make_pair(x, y);
            int ans=cnt[fi(g[id])];
            printf("%d\n", ans);
        }
    }
    return 0;
}