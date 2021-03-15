// Problem: True Story
// URL: https://codeforces.com/gym/103117/problem/M
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, x, s, t1[110000], t2[110000];
multiset<double> p;

int main(){
    int m=0;
    scanf("%d%d%d%d", &n, &k, &x, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &s);
        p.insert((double)x/s);
    }
    for(int i=1; i<=k; i++) scanf("%d", &t1[i]);
    for(int i=1; i<=k; i++){
        scanf("%d", &t2[i]);
        m=max(m, t2[i]-t1[i]);
    }
    int ans=0;
    for(auto num:p){
        if(num<=m) ans++;
    }
    printf("%d\n", ans);
    return 0;
}


