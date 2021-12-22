// Problem: Make It Good
// URL: https://codeforces.com/gym/302311/problem/J
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, a[210000];

void solve(){
    scanf("%d", &n);
    int i, fr=0, last=n;
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    for(i=n-1; i>0; i--){
        if (a[i]>=a[i+1]) {
            last = i;
        }
        else break;
    }
    for(i=last-1; i>0; i--){
        if (a[i] > a[i+1]) {
            fr = i;
            break;
        }
    }
    printf("%d\n", fr);

}

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
