// Problem: Killjoy
// URL: https://codeforces.com/gym/305901/problem/D
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, sum, x;

void solve(){
    int cnt=0;
    sum=0;
    scanf("%d%d", &n, &x);
    int num;
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(num==x) cnt++;
        sum+=num;
    }
    if(cnt==n) printf("%d\n", 0);
    else if(sum==x*n || cnt>=1) printf("%d\n", 1);
    else printf("%d\n", 2);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
