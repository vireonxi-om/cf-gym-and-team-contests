// Problem: Good Subarrays
// URL: https://codeforces.com/gym/306200/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, p[110000];
long long result;

void solve(){
    int sum=0, num;
    p[0]=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%1d", &num);
        sum+=num;
        p[i]=sum;
        p[i]-=i;
    }
    sort(p, p+n+1);
    int cnt=0, now=0; result=0;
    for(int j=0; j<=n; j++){
        if(p[j]==now) cnt++;
        if(p[j]!=now || j==n){
            result+=(long long)cnt*(cnt-1)/2;
            cnt=1;
            now=p[j];
        }
    }
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

