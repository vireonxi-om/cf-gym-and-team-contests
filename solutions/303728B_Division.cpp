// Problem: Division
// URL: https://codeforces.com/gym/303728/problem/B
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p, q, result;

LL pw(LL a, int b){
    LL result = 1;
    for(int i = 1; i <= b; i++){
        result*=a;
    }
    return result;
}

void solve(){
    scanf("%lld %lld", &p, &q);
    if(p%q!=0) result=p;
    else{
        map <LL, int> cnt;
        for(LL i = 2; i <= sqrt(q); i++){
            if(q % i == 0){
                while(q % i == 0){
                    cnt[i]++; q/=i;
                }
            }
        }
        if (q > 1) cnt[q]++;
        result = 1;
        for(auto [x, y] : cnt){
            LL P = p;
            int c = 0;
            while(P % x == 0) {
                P /= x;
                c++;
            }
            result = max(result, p / pw(x, c-y+1));
        }
    }
    printf("%lld\n", result);
}


int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
