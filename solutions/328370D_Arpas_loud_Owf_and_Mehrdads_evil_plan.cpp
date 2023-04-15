// Problem: Arpa's loud Owf and Mehrdad's evil plan
// URL: https://codeforces.com/gym/328370/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[110], yes[110];

int gcd(int x, int y){
    return y==0? x: gcd(y, x%y);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){ scanf("%d", &a[i]); yes[a[i]]=1;}
    bool can=true;
    for(int i=1; i<=n; i++) if(!yes[i]) can=false;
    ll ans=1;
    if(can){
        for(int i=1; i<=n; i++){
            int st=i, t=a[i], cnt=1;
            while(t!=st){
                t=a[t]; cnt++;
            }
            if(cnt%2) ans=(ll)ans*cnt/gcd(ans, cnt);
            else ans=(ll)ans*cnt/gcd(ans, cnt/2)/2;
        }
        printf("%lld\n", ans);
    }
    else printf("-1\n");
    return 0;
}
