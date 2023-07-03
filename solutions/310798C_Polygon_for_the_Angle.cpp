// Problem: Polygon for the Angle
// URL: https://codeforces.com/gym/310798/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int ang;

void solve(){
    scanf("%d", &ang);
    bool big=false;
    int ans;
    if(ang==90) ans=4;
    else if(ang>90){
        ang=180-ang;
        big=true;
    }
    ang*=2;
    for(int i=3; i<=360; i++){
        if((ang*i)%360==0){
            if(big && ang*i/360==1) continue;
            else{
                ans=i;
                break;
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

