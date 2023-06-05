// Problem: Slava and tanks
// URL: https://codeforces.com/gym/320372/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;

int main(){
    scanf("%d", &n);
    int ans=n+n/2; printf("%d\n", ans);
    if(n%2==0){
        for(int i=1; i<=n; i+=2) printf("%d ", i);
        for(int i=2; i<=n; i+=2) printf("%d ", i);
        for(int i=1; i<=n; i+=2) printf("%d ", i);
    }
    else{
        for(int i=2; i<=n; i+=2) printf("%d ", i);
        for(int i=1; i<=n; i+=2) printf("%d ", i);
        for(int i=2; i<=n; i+=2) printf("%d ", i);
    }
    printf("\n");
}
