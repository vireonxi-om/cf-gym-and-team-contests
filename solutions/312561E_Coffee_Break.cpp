// Problem: Coffee Break
// URL: https://codeforces.com/gym/312561/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, d, ans[210000];
set<pair<int, int>> a;

int main(){
    scanf("%d%d%d", &n, &m, &d);
    for(int i=1; i<=n; i++){
        int num;
        scanf("%d", &num);
        a.insert(make_pair(num, i));
    }
    int day=1;
    while(!a.empty()){
        auto it=a.begin();
        while(it!=a.end()){
            ans[(*it).second]=day;
            int now=(*it).first+d+1;
            a.erase(it);
            it=a.lower_bound(make_pair(now, 0));
        }
        day++;
    }
    printf("%d\n", day-1);
    for(int i=1; i<=n; i++) printf("%d ", ans[i]);
    printf("\n");
}