// Problem: Advertising Agency
// URL: https://codeforces.com/gym/314674/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k, cnt[1100], inv[1100];
vector<pair<int, int>> a;
const int M=1000000007;

void inver(int n, int p) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] =((ll) (p - p / i) * inv[p % i]) % p;
    }
}

void solve(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) cnt[i]=0; a.clear();
    for(int i=1; i<=n; i++){
        int num;
        scanf("%d", &num);
        cnt[num]++;
    }
    for(int i=1; i<=n; i++){
        if(cnt[i]) a.push_back(make_pair(i, cnt[i]));
    }
    sort(a.begin(), a.end(), greater<>());
    inver(n, 1000000007);
    ll result=1;
    auto it=a.begin();
    while(k>0){
        auto p=(*it);
        if(k>=p.second){
            k-=p.second;
        }
        else{
            for(int i=p.second; i>p.second-k; i--){ result*=i; result%=M;}
            for(int i=k; i>=1; i--){ result*=inv[i]; result%=M;}
            k=0;
        }
        it++;
    }
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}