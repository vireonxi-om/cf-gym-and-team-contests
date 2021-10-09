// Problem: Binary Table (Easy Version)
// URL: https://codeforces.com/gym/305901/problem/C
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, m;

void solve(){
    scanf("%d%d", &n, &m);
    int num;
    vector<vector<int>> ans;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &num);
            if(num==1){
                int s=1, t=1;
                if(i==n) s=-1;
                if(j==m) t=-1;
                ans.push_back({i, j, i+s, j, i+s, j+t});
                ans.push_back({i, j, i, j+t, i+s, j+t});
                ans.push_back({i, j, i+s, j, i, j+t});
            }
        }
    }
    printf("%d\n", ans.size());
    for(auto x:ans){
        for(auto y:x) printf("%d ", y);
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

