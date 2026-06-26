// Problem: Omkar and Last Class of Math
// URL: https://codeforces.com/gym/303728/problem/A
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n;

void solve(){
    scanf("%d", &n);
    bool yes=false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            printf("%d %d\n", n/i, n-n/i);
            yes=true;
            break;
        }
    }
    if(!yes)
        printf("%d %d\n", 1, n-1);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
