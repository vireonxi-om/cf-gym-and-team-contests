// Problem: Divide Candies
// URL: https://codeforces.com/gym/312561/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, num[1100];

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++){
        int now=i, t=n/m;
        if(now+t*m>n) num[(i*i)%m]+=t;
        else num[(i*i)%m]+=t+1;
    }
    ll result=0;
    result+=(ll)num[0]*num[0];
    for(int i=1; i<=m/2; i++){
        if(2*i!=m) result+=(ll)2*num[i]*num[m-i];
        else result+=(ll)num[i]*num[i];
    }
    /*
    for(int i=0; i<m; i++){
        for(auto x:t[i]) printf("%d ", x);
        printf("\n");
    }*/
    printf("%lld\n", result);
}

