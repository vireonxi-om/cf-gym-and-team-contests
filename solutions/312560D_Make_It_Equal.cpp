// Problem: Make It Equal
// URL: https://codeforces.com/gym/312560/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k, h[210000], hmin=1e6, hmax=0;

int main(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) {
        int num;
        scanf("%d", &num);
        hmin=min(hmin, num); hmax=max(hmax, num);
        h[num]++;
    }
    for(int i=hmax; i>=1; i--) h[i]+=h[i+1];
    int t=hmax, result=0;
    while(t>hmin){
        int now=k;
        while(now>=h[t]){
            now-=h[t]; t--;
        }
        result++;
    }
    printf("%d\n", result);
}