// Problem: Alyona and Spreadsheet
// URL: https://codeforces.com/gym/328082/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, t[110000];
vector<int> g[110000];


int main(){
    scanf("%d%d", &n, &m);
    int num;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &num);
            g[i].push_back(num);
        }
    }
    for(int i=1; i<=n; i++) t[i]=i;
    for(int j=0; j<m; j++){
        int st=1, ed;
        while(st<n){
            ed=st;
            while(ed<n && g[ed+1][j]>=g[ed][j]) ed++;
            t[st]=max(t[st], ed);
            st=ed+1;
        }
    }
    for(int i=2; i<=n; i++){
        t[i]=max(t[i], t[i-1]);
    }
    int k, l, r;
    scanf("%d", &k);
    while(k--){
        scanf("%d%d", &l, &r);
        if(t[l]<r) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
