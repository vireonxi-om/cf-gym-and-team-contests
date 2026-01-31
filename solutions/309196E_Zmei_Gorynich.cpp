// Problem: Zmei Gorynich
// URL: https://codeforces.com/gym/309196/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x, a[110][2];

void solve(){
    int maxb=0, maxd=0;
    scanf("%d%d", &n, &x);
    for(int i=1; i<=n; i++){
        scanf("%d%d", &a[i][0], &a[i][1]);
        maxb=max(maxb, a[i][0]);
        maxd=max(maxd, a[i][0]-a[i][1]);
    }
    if(x>maxb && maxd<=0){ printf("-1\n"); return;}
    int ans=1;
    if(x>maxb) ans+=(x-maxb+maxd-1)/maxd;
    printf("%d\n", ans);

}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
