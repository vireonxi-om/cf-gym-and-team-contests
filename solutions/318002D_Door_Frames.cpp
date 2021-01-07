// Problem: Door Frames
// URL: https://codeforces.com/gym/318002/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a, b;

int main(){
    scanf("%d%d%d", &n, &a, &b);
    int ans=6;
    if(4*a<=n){
        if(4*a+2*b<=n) ans=1;
        else if(4*a+b<=n || 2*b<=n) ans=min(ans, 2);
        else ans=min(ans, 3);
    }
    if(3*a<=n){
        if(3*a+b<=n || a+2*b<=n) ans=min(ans, 2);
        else if(a+b<=n || 2*b<=n) ans=min(ans, 3);
        else ans=min(ans, 4);
    }
    if(2*a<=n){
        if(2*a+b<=n) ans=min(ans, 2);
        else if(a+b<=n || 2*b<=n) ans=min(ans, 3);
        else ans=min(ans, 4);
    }
    if(a+b<=n) ans=min(ans, 4);
    else if(2*b<=n) ans=min(ans, 5);
    printf("%d\n", ans);
}
