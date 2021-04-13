// Problem: The Phone Number
// URL: https://codeforces.com/gym/314707/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;

int main(){
    scanf("%d", &n);
    int m=1e9, ans;
    for(int i=1; i<=n; i++){
        int now=i;
        now+=(n+i-1)/i;
        if(now<m){
            ans=i;
            m=now;
        }
    }
    int t=n/ans, num=n%ans;
    for(int i=1; i<=t; i++){
        for(int j=1; j<=ans; j++){
            printf("%d ", n-i*ans+j);
        }
    }
    for(int i=1; i<=num; i++) printf("%d ", i);
    printf("\n");
    return 0;
}