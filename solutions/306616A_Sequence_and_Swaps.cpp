// Problem: Sequence and Swaps
// URL: https://codeforces.com/gym/306616/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, x, a[510];

bool checkinc(int i, int j){
    bool r=true;
    for(int k=i; k<=j; k++){
        if(a[k+1]<a[k]) r=false;
    }
    return r;
}

void solve(){
    scanf("%d%d", &n, &x);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    bool can=true;
    int cnt=0;
    for(int i=1; i<n; i++){
        if(checkinc(i, n-1)) break;
        else{
            if(a[i]>x){
                swap(a[i], x);
                cnt++;
            }
            if(a[i+1]<a[i]){
                can=false;
                break;
            }
        }
    }
    if(can) printf("%d\n", cnt);
    else printf("-1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

