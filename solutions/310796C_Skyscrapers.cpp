// Problem: Skyscrapers
// URL: https://codeforces.com/gym/310796/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, a[1100][1100], sumr[1100], sumc[1100], rnkr[1100][1100], rnkc[1100][1100];

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", &a[i][j]);
    for(int i=1; i<=n; i++){
        set<int> now;
        for(int j=1; j<=m; j++) now.insert(a[i][j]);
        vector<int> row (now.begin(), now.end());
        sumr[i]=row.size();
        for(int j=1; j<=m; j++){
            rnkr[i][j]=lower_bound(row.begin(), row.end(), a[i][j])-row.begin()+1;
        }
    }
    for(int j=1; j<=m; j++){
        set<int> now;
        for(int i=1; i<=n; i++) now.insert(a[i][j]);
        vector<int> col (now.begin(), now.end());
        sumc[j]=col.size();
        for(int i=1; i<=n; i++){
            rnkc[i][j]=lower_bound(col.begin(), col.end(), a[i][j])-col.begin()+1;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            printf("%d ", max(rnkc[i][j], rnkr[i][j])+max(sumc[j]-rnkc[i][j], sumr[i]-rnkr[i][j]));
        }
        printf("\n");
    }
}

