// Problem: Weakened Common Divisor
// URL: https://codeforces.com/gym/314707/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
set<int> ans;

int main(){
    scanf("%d", &n);
    n--;
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i=2; i<=sqrt(a)+1; i++){
        if(a%i==0){
            ans.insert(i);
            while(a%i==0) a/=i;
        }
    }
    if(a>1) ans.insert(a);
    for(int i=2; i<=sqrt(b)+1; i++){
        if(b%i==0){
            ans.insert(i);
            while(b%i==0) b/=i;
        }
    }
    if(b>1) ans.insert(b);
    while(n--){
        scanf("%d%d", &a, &b);
        vector<int> temp;
        for(auto x:ans){
            if(a%x==0 || b%x==0) temp.push_back(x);
        }
        ans.clear();
        for(auto x:temp) ans.insert(x);
    }
    if(ans.empty()) printf("-1\n");
    else printf("%d\n", (*ans.begin()));
    return 0;
}