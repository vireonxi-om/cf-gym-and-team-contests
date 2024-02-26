// Problem: Decrease the Sum of Digits
// URL: https://codeforces.com/gym/305901/problem/G
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, s, result, a[20];

ll power(int a, int b){
    ll result=1;
    while(b>0){
        result=result*a;
        b--;
    }
    return result;
}

void solve(){
    memset(a, 0, sizeof(a));
    scanf("%lld%lld", &n, &s);
    ll m=n; int i=0;
    while(m>0){
        a[i]=m%10;
        m-=a[i]; m/=10;
        i++;
    }
    i--;
    ll sum=0; int k=-1;
    for(int j=i; j>=0; j--){
        sum+=a[j];
        if(sum>s){
            k=j+1; break;
        }
        else if(sum==s){
            bool yes=false;
            for(int t=0; t<j; t++){
                if(a[t]!=0) yes=true;
            }
            if(yes){
                k=j+1; break;
            }
        }
    }
    if(k==-1){
        printf("0\n"); return;
    }
    while(a[k]==9) k++;
    a[k]++;
    result=0;
    for(int j=k; j<=19; j++) result+=a[j]*power(10, j);
    printf("%lld\n", result-n);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

