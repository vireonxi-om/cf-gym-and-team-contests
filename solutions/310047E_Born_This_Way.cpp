// Problem: Born This Way
// URL: https://codeforces.com/gym/310047/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ta, tb, k, a[210000], b[210000];

int main(){
    scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        a[i]+=ta;
    }
    for(int i=1; i<=m; i++) scanf("%d", &b[i]);
    bool can=true;
    int result=0;
    if(k>=n || k>=m) can=false;
    else for(int i=0; i<=k; i++){
        auto it=lower_bound(b+1, b+m+1, a[i+1]);
        it+=(k-i);
        if(it>=b+m+1) can=false;
        else result=max(result, (*it)+tb);
    }
    if(can) printf("%d\n", result);
    else printf("-1\n");
    return 0;
}
