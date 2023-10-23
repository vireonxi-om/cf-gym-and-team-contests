// Problem: From Y to Y
// URL: https://codeforces.com/gym/320373/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, cnt[30];

int main(){
    scanf("%d", &n);
    int now=0;
    while(n){
        int i;
        for(i=1; ; i++){
            if((i+2)*(i+1)/2>n) break;
        }
        cnt[now]=i;
        n-=(i+1)*i/2;
        now++;
    }
    int t=0;
    while(1){
        for(int i=1; i<=cnt[t]+1; i++) printf("%c", 'a'+t);
        if(cnt[t+1]==0) break;
        t++;
    }
    printf("\n");
}

