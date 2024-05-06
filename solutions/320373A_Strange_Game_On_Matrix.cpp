// Problem: Strange Game On Matrix
// URL: https://codeforces.com/gym/320373/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, k, a[110][110];

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int sum=0, ans=0;
    for(int j=1; j<=m; j++){
        for(int i=1; i<=n; i++){
            a[i][j]+=a[i-1][j];
        }
        int pos=0, tot=-1;
        for(int i=1; i<=n-k+1; i++){
            int now=a[i+k-1][j]-a[i-1][j];
            if(now>tot){
                tot=now; pos=i;
            }
        }
        ans+=a[pos-1][j];
        sum+=tot;
    }
    printf("%d %d\n", sum, ans);
    return 0;
}