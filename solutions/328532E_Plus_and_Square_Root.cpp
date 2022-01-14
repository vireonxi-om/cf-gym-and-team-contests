// Problem: Plus and Square Root
// URL: https://codeforces.com/gym/328532/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[110000];
set<pair<int, int>> s;
multiset<ll> ans;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        if(i==1) printf("2\n");
        else{
            printf("%lld\n", (ll)i*(i+1)*(i+1)-i+1);
        }
    }
    return 0;
}