// Problem: Special Permutation
// URL: https://codeforces.com/gym/307718/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void solve(){
    scanf("%d", &n);
    int now=n;
    if(n==2||n==3){ printf("-1\n");return;}
    while(now>=12){
        now-=6;
        printf("%d %d %d %d %d %d ", now+6, now+4, now+1, now+3, now+5, now+2);
    }
    if(now%6==2) printf("7 4 1 3 5 8 6 2\n");
    else if(now%6==3) printf("9 7 4 1 3 5 8 6 2\n");
    else{
        if(now>6){
            now-=6;printf("%d %d %d %d %d %d ", now+6, now+4, now+1, now+3, now+5, now+2);
        }
        if(now==4) printf("3 1 4 2\n");
        else if(now==5) printf("5 3 1 4 2\n");
        else if(now==6) printf("6 4 1 3 5 2\n");
        else if(now==1) printf("1\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
