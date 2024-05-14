// Problem: Boboniu and Bit Operations
// URL: https://codeforces.com/gym/306616/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, m, a[210], b[210], c[210];

bool check(int p, int i){
    bool result=false;
    for(int j=1; j<=m; j++)
        if(p==(a[i]&b[j]|p)) result=true;
    return result;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=m; i++) scanf("%d", &b[i]);
    int p;
    for(p=0; p<=512; p++){
        bool can=true;
        for(int i=1; i<=n; i++)
            if(!check(p,i)) can=false;
        if(can) break;
    }
    printf("%d\n", p);
    return 0;
}

