// Problem: Number Game
// URL: https://codeforces.com/gym/305901/problem/I
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n;

void solve(){
    scanf("%d", &n);
    bool f=false;
    int m=0;
    while (n%2==0){
        n/=2; m++;
    }
    if(n==1 && m!=1) f=true;
    else if(m==1 && n!=1){
        bool yes=true;
        for(int i=2; i<=sqrt(n); i++)
            if(n%i==0) yes=false;
        if(yes) f=true;
    }
    if(f) printf("FastestFinger\n");
    else printf("Ashishgup\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
