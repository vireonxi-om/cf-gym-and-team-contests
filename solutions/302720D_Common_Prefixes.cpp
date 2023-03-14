// Problem: Common Prefixes
// URL: https://codeforces.com/gym/302720/problem/D
// Rating: 1200
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
char a[60];
int n, num;

void solve(){
    scanf("%d", &n);
    printf("%s\n", a);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(a[num]=='z') a[num]='a';
        else a[num]++;
        printf("%s\n", a);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<60; i++) a[i]='a';
    a[60]='\0';
    for(int i=0; i<t; i++) solve();
    return 0;
}
