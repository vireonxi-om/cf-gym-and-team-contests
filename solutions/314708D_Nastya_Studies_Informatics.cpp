// Problem: Nastya Studies Informatics
// URL: https://codeforces.com/gym/314708/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int l, r, x, y;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    scanf("%d%d%d%d", &l, &r, &x, &y);
    int num=y/x;
    int cnt1=0, cnt0=0;
    for(int i=1; i<=sqrt(num); i++){
        if(num%i==0){
            int a=i, b=num/i;
            if(gcd(a,b)!=1) continue;
            if(a*x>=l && b*x>=l && a*x<=r && b*x<=r){
                if(a==b) cnt1++;
                else cnt0++;
            }
        }
    }
    int ans=cnt0*2+cnt1;
    if(y%x!=0) printf("0\n");
    else printf("%d\n", ans);
    return 0;
}