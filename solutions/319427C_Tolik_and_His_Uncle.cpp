// Problem: Tolik and His Uncle
// URL: https://codeforces.com/gym/319427/problem/C
// Rating: 1800
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m;
vector<pair<int, int>> ans;

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n/2; i++){
        for(int j=1; j<=m; j++){
            ans.push_back(make_pair(i, j));
            ans.push_back(make_pair(n-i+1, m-j+1));
        }
    }
    if(n%2){
        int t=n/2+1;
        for(int j=1; j<=m/2; j++){
            ans.push_back(make_pair(t, j));
            ans.push_back(make_pair(t, m-j+1));
        }
        if(m%2){
            ans.push_back(make_pair(t, m/2+1));
        }
    }
    for(auto x:ans){
        printf("%d %d\n", x.first, x.second);
    }
    return 0;
}
