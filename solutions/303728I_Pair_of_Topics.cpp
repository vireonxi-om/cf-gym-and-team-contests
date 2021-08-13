// Problem: Pair of Topics
// URL: https://codeforces.com/gym/303728/problem/I
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, result;
int a[210000];

int main(){
    result=0;
    scanf("%lld", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num); a[i]-=num;
    }
    sort(a+1, a+n+1);
    int j=1, k=n;
    while(a[j]<=0){
        while (a[j]+a[k]>0) k--;
        result+=n-k;
        j++;
    }
    if(n+1-j>1){
        result+=(n+1-j)*(n-j)/2;
    }
    printf("%lld\n", result);
    return 0;
}
