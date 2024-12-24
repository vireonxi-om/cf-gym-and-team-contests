// Problem: Tram
// URL: https://codeforces.com/gym/328370/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int s, p, d, t1, t2, st, t;

int cal(int x1, int a){
    if(x1>a) return 2*s-x1-a;
    else if(x1>-a) return a-x1;
    else return -a-x1;
}

int main(){
    scanf("%d%d%d%d%d", &s, &p, &d, &t1, &t2);
    scanf("%d%d", &st, &t);
    st*=t;
    int ans;
    if(st>p){
        ans=cal(st, p)+cal(-p, d);
    }
    else if(st>-p) ans=cal(st, p)+cal(p, d);
    else ans=cal(st, p)+cal(-p, d);
    ans*=t1;
    ans=min(ans, t2*abs(p-d));
    printf("%d\n", ans);
    return 0;
}
