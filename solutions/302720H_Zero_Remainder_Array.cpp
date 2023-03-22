// Problem: Zero Remainder Array
// URL: https://codeforces.com/gym/302720/problem/H
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
long long result;
int n, k;

void solve(){
    map<int, int> cnt;
    int num, maxi=0;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if((num%k)!=0){
            cnt[k-num%k]++;
            maxi=max(maxi, cnt[k-num%k]);
        }
    }
    result=0;
    for(auto [x, y]:cnt){
        if (y==maxi){
            result=(long long)k*(maxi-1)+x+1;
        }
    }
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
