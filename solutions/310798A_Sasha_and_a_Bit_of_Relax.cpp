// Problem: Sasha and a Bit of Relax
// URL: https://codeforces.com/gym/310798/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[310000], pre[310000], b[310000];
map<int, int> ans0, ans1;
ll result;

int main(){
    scanf("%d", &n);
    for(int i=2; i<=n; i++) b[i]=b[i-1]*i;
    pre[0]=0; ans0[0]++;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        pre[i]=pre[i-1]^a[i];
        if(i%2==0) ans0[pre[i]]++;
        else ans1[pre[i]]++;
    }
    for(auto x:ans0) result+=(ll)x.second*(x.second-1)/2;
    for(auto x:ans1) result+=(ll)x.second*(x.second-1)/2;
    printf("%lld\n",result);
}
