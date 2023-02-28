// Problem: Cards Sorting
// URL: https://codeforces.com/gym/322393/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
vector<int> g[110000], a;


int main(){
    scanf("%d", &n);
    int num, m=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        g[num].push_back(i);
        m=max(m, num);
    }
    for(int i=1; i<=m; i++) if(!g[i].empty()) a.push_back(i);
    auto it1=a.begin();
    ll ans=0;
    int now=n;
    while(it1!=a.end()){
        auto it2=it1, it3=it1; it2++;
        while(it2!=a.end() && (*(--g[(*it3)].end()))<(*g[(*it2)].begin())){
            it2++; it3++;
        }
        int cnt=0;
        if(it2!=a.end()){
            int t=(*it2), lst=(*(--g[(*it3)].end()));
            auto j=g[t].end(); j--;
            while((*j)>lst){
                cnt++;
                g[t].erase(j);
                j=g[t].end(); j--;
            }
        }
        for(auto it=it1; it<=it3; it++){
            cnt+=g[(*it)].size();
        }
        if(it2==a.end()){
            ans+=cnt;
            break;
        }
        ans+=now;
        now-=cnt;
        it1=it2;
    }
    printf("%lld\n", ans);
    return 0;
}