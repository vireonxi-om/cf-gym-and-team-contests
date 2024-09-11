// Problem: Mischievous Problem Setter
// URL: https://codeforces.com/gym/102055/problem/A
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[110000], b[110000];
set<pair<int, int>> s;

void solve(int t){
    s.clear();
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) scanf("%d", &b[i]);
    for(int i=1; i<=n; i++) s.insert(make_pair(a[i], b[i]));
    int cnt=0;
    for(auto x:s){
        if(m>=x.second){ m-=x.second; cnt++;}
        else break;
    }
    printf("Case %d: %d\n", t, cnt);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve(i);
    return 0;
}