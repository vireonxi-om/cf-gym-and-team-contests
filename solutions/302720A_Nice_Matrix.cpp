// Problem: Nice Matrix
// URL: https://codeforces.com/gym/302720/problem/A
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
long long a[110][110], b[4], result;
int m, n;
void solve(){
    scanf("%d%d", &n, &m);
    result=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) scanf("%lld", &a[i][j]);
    }
    for(int i=1; i<=n/2; i++){
        for(int j=1; j<=m/2; j++){
            b[0]=a[i][j];
            b[1]=a[n-i+1][j];
            b[2]=a[i][m-j+1];
            b[3]=a[n-i+1][m-j+1];
            sort(b, b+4);
            result+=b[3]+b[2]-b[1]-b[0];
        }
    }
    if(n%2==1){
        for(int j=1; j<=m/2; j++)
            result+=abs(a[n/2+1][j]-a[n/2+1][m-j+1]);
    }
    if(m%2==1){
        for(int i=1; i<=n/2; i++)
            result+=abs(a[i][m/2+1]-a[n-i+1][m/2+1]);
    }
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
