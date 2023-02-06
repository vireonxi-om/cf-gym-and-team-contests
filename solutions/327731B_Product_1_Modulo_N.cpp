// Problem: Product 1 Modulo N
// URL: https://codeforces.com/gym/327731/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> ans;

int gcd(int x, int y){
    return y==0 ? x : gcd(y, x%y);
}
int main(){
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        if(gcd(i, n)>1) continue;
        ans.push_back(i);
    }
    ll p=1;
    for(auto x:ans) {
        p*=x; p%=n;
    }
    if(p>1) printf("%d\n", ans.size()-1);
    else printf("%d\n", ans.size());
    for(auto x:ans){
        if(x==p && p>1) continue;
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
