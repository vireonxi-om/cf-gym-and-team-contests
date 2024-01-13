// Problem: Riana and Humongous Numbers
// URL: https://codeforces.com/gym/102556/problem/H
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
ll n, m, p[60];

ll power(ll num, int t){
    if(t==0) return 1;
    ll result=1;
    if(t%2) result*=num;
    result*=power(num*num, t/2);
    return result;
}

ll cnt(ll num){
    ll ans=0;
    for(int i=1; i<=sqrt(num); i++){
        if(num%i) continue;
        ans++;
    }
    return ans;
}

int main(){
    scanf("%lld", &m);
    ll num=cnt(m);
    if(num==1){ printf("%lld\n", m); return 0;}
    n=-1;
    ll now=1;
    for(int i=50; i>=2; i--){
        while(power(now, i)<=m) now++;
        now--;
        p[i]=now;
    }
    for(int i=2; i<=50; i++){
        num=p[i];
        //printf("%d %lld\n", i, num);
        if(power(num, i)!=m) continue;
        ll cnt1=cnt(num), cnt2=cnt(num*num);
        //printf("%lld %lld\n", cnt1, cnt2);
        if(cnt1==i && (int)sqrt(num)*(int)sqrt(num)!=num){ n=num; break;}
        if(i%2){
            if(cnt2-1==(i-1)/2){ n=num*num; break;}
        }
    }
    printf("%lld\n", n);
    return 0;
}

