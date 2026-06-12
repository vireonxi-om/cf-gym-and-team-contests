// Problem: The Meeting Place Cannot Be Changed
// URL: https://codeforces.com/gym/328082/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, s[61000], v[61000];


int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &s[i]);
    for(int i=1; i<=n; i++) scanf("%d", &v[i]);
    double l=0, r=1000000100, ans;
    while(r-l>1e-9){
        double mid=(l+r)/2;
        double t1=0, t2=0;
        for(int i=1; i<=n; i++){
            if(s[i]>mid) t1=max(t1, (double)(s[i]-mid)/v[i]);
            else t2=max(t2, (double)(mid-s[i])/v[i]);
        }
        ans=t1;
        if(t1>t2) l=mid;
        else r=mid;
    }
    printf("%.8f\n", ans);
    return 0;
}
