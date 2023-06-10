// Problem: Two Arrays
// URL: https://codeforces.com/gym/309004/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, cnt[25][1100];

int main(){
    scanf("%d%d", &n, &m);
    for(int j=1; j<=n; j++) cnt[2*m][j]=1;
    for(int i=1; i<=2*m; i++) cnt[i][n]=1;
    for(int i=2*m-1; i>=1; i--){
        for(int j=n-1; j>=1; j--){
            cnt[i][j]=cnt[i][j+1]+cnt[i+1][j];
            cnt[i][j]=cnt[i][j]%(1000000007);
        }
    }
    int result=0;
    for(int j=1; j<=n; j++){
        result+=cnt[1][j];
        result=result%(1000000007);
    }
    printf("%d\n", result);
}
