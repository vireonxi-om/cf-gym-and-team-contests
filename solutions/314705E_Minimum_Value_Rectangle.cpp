// Problem: Minimum Value Rectangle
// URL: https://codeforces.com/gym/314705/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
map<int, int> cnt;

void solve(){
    scanf("%d", &n);
    cnt.clear();
    for(int i=1; i<=n; i++){
        int num;
        scanf("%d", &num);
        cnt[num]++;
    }
    vector<int> pos;
    for(auto x:cnt){
        if(x.second>=4){
            int t=x.first;
            printf("%d %d %d %d\n", t, t, t, t);
            return;
        }
        else if(x.second>=2) pos.push_back(x.first);
    }
    int len=pos.size(), ans=0;
    double r=1e8;
    for(int i=0; i<len-1; i++){
        double now=(double)pos[i+1]/pos[i];
        if(now<r){ r=now; ans=i;}
    }
    printf("%d %d %d %d\n", pos[ans], pos[ans], pos[ans+1], pos[ans+1]);
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}