// Problem: Element Extermination
// URL: https://codeforces.com/gym/302720/problem/I
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, a[310000];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    if(a[1]<a[n]) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
