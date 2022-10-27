// Problem: Takeaway
// URL: https://codeforces.com/gym/103145/problem/I
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[10];
const ll M=998244353;

void solve(){
    scanf("%d", &n);
    int num, sum=0, ans;
    a[1]=7; a[2]=27; a[3]=41; a[4]=49; a[5]=63; a[6]=78; a[7]=108;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        sum+=a[num];
    }
    if(sum>=120) ans=sum-50;
    else if(sum>=89) ans=sum-30;
    else if(sum>=69) ans=sum-15;
    else ans=sum;
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

