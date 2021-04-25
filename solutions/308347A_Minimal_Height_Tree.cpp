// Problem: Minimal Height Tree
// URL: https://codeforces.com/gym/308347/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[210000];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    int now=2, cnt=1, result=0;
    while(now<=n){
        int upd=0;
        while(cnt>0){
            int t=1;
            while(now<n && a[now+1]>a[now]){
                now++;
                t++;
            }
            now++;
            upd+=t;
            cnt--;
        }
        cnt=upd;
        result++;
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
