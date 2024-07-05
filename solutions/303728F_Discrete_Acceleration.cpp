// Problem: Discrete Acceleration
// URL: https://codeforces.com/gym/303728/problem/F
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, l, a[110000];
double t1[110000], t2, t;

void solve(){
    scanf("%d%d", &n, &l);
    a[0]=0; a[n+1]=l;
    t1[0]=0; t2=0; t=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        t1[i]=t1[i-1]+(double)(a[i]-a[i-1])/i;
    }
    int s;
    for(s=n; s>0; s--){
        t2+=(double)(a[s+1]-a[s])/(n+1-s);
        if(t2>t1[s]){
            t2-=(double)(a[s+1]-a[s])/(n+1-s);
            break;
        }
    }
    t=(double)(a[s+1] - a[s] + (s+1)*t1[s] + (n+1-s)*t2)/(n+2);
    printf("%.15f\n", t);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
