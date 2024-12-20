// Problem: Game with Chips
// URL: https://codeforces.com/gym/308172/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, sx, sy, fx, fy;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=k; i++){
        scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    }
    vector<char> ans;
    char now='U';
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++) ans.push_back(now);
        now='D'+'U'-now;
        ans.push_back('L');
    }
    for(int j=1; j<n; j++) ans.push_back(now);
    for(int i=1; i<m; i++){
        now='D'+'U'-now;
        for(int j=1; j<n; j++) ans.push_back(now);
        ans.push_back('R');
    }
    now='D'+'U'-now;
    for(int j=1; j<n; j++) ans.push_back(now);
    printf("%d\n", 2*n*m-2);
    for(auto x:ans) printf("%c", x);
    printf("\n");
    return 0;
}

