// Problem: Three-level Laser
// URL: https://codeforces.com/gym/318001/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, u;
vector<int> e;

int main(){
    scanf("%d%d", &n, &u);
    for(int i=1; i<=n; i++){
        int num;
        scanf("%d", &num);
        e.push_back(num);
    }
    double ans=0;
    bool can=false;
    for(int i=0; i<n-2; i++){
        auto it=lower_bound(e.begin(), e.end(), e[i]+u);
        if(it==e.end() || (*it)>e[i]+u) it--;
        if((*it)-e[i+1]>0) can=true;
        else continue;
        ans=max(ans, (double)((*it)-e[i+1])/((*it)-e[i]));
    }
    if(can) printf("%.11f\n", ans);
    else printf("-1\n");
    return 0;
}
