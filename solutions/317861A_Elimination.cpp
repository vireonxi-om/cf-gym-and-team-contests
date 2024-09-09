// Problem: Elimination
// URL: https://codeforces.com/gym/317861/problem/A
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, c, d, k;


int main(){
    scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
    int ans=1e9;
    for(int i=0; i<=m; i++){
        int cur=0;
        cur+=i*c;
        if(i*n+k<n*m) cur+=(n*m-k-i*n)*d;
        ans=min(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}
