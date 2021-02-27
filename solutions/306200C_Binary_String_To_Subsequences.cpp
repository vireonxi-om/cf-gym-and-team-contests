// Problem: Binary String To Subsequences
// URL: https://codeforces.com/gym/306200/problem/C
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, a[210000], b[210000];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%1d", &a[i]);
    queue<int> q[2];
    int tot=0;
    for(int i=1; i<=n; i++){
        if(q[1-a[i]].empty()){
            tot++;
            q[a[i]].push(tot);
            b[i]=tot;
        }
        else{
            q[a[i]].push(q[1-a[i]].front());
            b[i]=q[1-a[i]].front();
            q[1-a[i]].pop();
        }
    }
    printf("%d\n", tot);
    for(int i=1; i<=n; i++) printf("%d ", b[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
