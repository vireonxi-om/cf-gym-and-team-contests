// Problem: Catch Overflow!
// URL: https://codeforces.com/gym/310046/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll a[110000];
char s[10];
const long long INF =1ll << 32;

int main(){
    int t;
    scanf("%d", &t);
    int loop=0;
    ll now=1, result=0;
    a[0]=1;
    bool can=true;
    while(t--){
        scanf("%s", &s);
        if(s[0]=='f'){
            int num;
            scanf("%d", &num);
            if(loop==0) a[1]=num;
            else a[loop+1]=min(INF, a[loop]*num);
            loop++;
        }
        if(s[0]=='e'){
            loop--;
        }
        if(s[0]=='a'){
            result+=a[loop];
            if(result>=INF) can=false;
        }
    }
    if(can) printf("%lld\n", result);
    else printf("OVERFLOW!!!\n");
    return 0;
}