// Problem: Circular Dance
// URL: https://codeforces.com/gym/310798/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
vector<int> g[210000], ans;

int main(){
    scanf("%d", &n);
    ans.push_back(1);
    if(n==3){ ans.push_back(2); ans.push_back(3);}
    for(int i=1; i<=n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[i].push_back(a);
        g[i].push_back(b);
    }
    while(ans.size()<n){
        auto it=ans.end();
        it--;
        int a=g[(*it)][0], b=g[(*it)][1];
        int c=g[a][0], d=g[a][1];
        if(c==b || d==b){ ans.push_back(a); ans.push_back(b);}
        else{ ans.push_back(b); ans.push_back(a);}
    }
    auto it=ans.begin();
    for(int i=1; i<=n; i++){
        printf("%d ", (*it));
        it++;
    }
    printf("\n");
}


