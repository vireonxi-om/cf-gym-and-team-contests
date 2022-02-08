// Problem: Permutation Game
// URL: https://codeforces.com/gym/314705/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110000], pos[110000];
char s[110000];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        pos[a[i]]=i;
    }
    s[pos[n]]='B';
    for(int t=n-1; t>=1; t--){
        int st=pos[t]%t;
        s[pos[t]]='B';
        for(int i=st; i<=n; i+=t){
            if(i==pos[t]) continue;
            if(a[i]>t && s[i]=='B') s[pos[t]]='A';
        }
    }
    printf("%s", s+1);
    return 0;
}