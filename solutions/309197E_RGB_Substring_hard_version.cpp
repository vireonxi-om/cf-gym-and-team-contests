// Problem: RGB Substring (hard version)
// URL: https://codeforces.com/gym/309197/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k, a[210000], pre[210000][3];
char s[210000];

void solve(){
    scanf("%d%d%s", &n, &k, &s);
    for(int i=0; i<n; i++){
        int num;
        if(s[i]=='R') num=0;
        else if(s[i]=='G') num=1;
        else num=2;
        a[i]=(num-(i%3)+3)%3;
    }
    for(int i=0; i<3; i++){
        pre[0][i]=0;
        for(int j=1; j<=n; j++){
            pre[j][i]=pre[j-1][i];
            if(a[j-1]==i) pre[j][i]++;
        }
    }
    int result=1e9;
    for(int i=0; i<3; i++){
        for(int j=0; j<=n-k; j++){
            int sum=pre[j+k][i]-pre[j][i];
            sum=k-sum;
            result=min(result, sum);
        }
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}