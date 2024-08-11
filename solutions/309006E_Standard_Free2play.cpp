// Problem: Standard Free2play
// URL: https://codeforces.com/gym/309006/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, h, a[210000];

void solve(){
    scanf("%d%d", &h, &n);
    for(int i=n; i>=1; i--) scanf("%d", &a[i]);
    int pos=n-1;
    int result=0;
    for(int i=h-1; i>=2;){
        if(a[pos]==i && a[pos-1]==i-1){
            pos-=2; i-=2;
        }
        else if(a[pos]<i){
            i=a[pos];
        }
        else{
            result++;
            pos--; i--;
        }
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
