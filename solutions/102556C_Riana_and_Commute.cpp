// Problem: Riana and Commute
// URL: https://codeforces.com/gym/102556/problem/C
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a, b, m[110], w[110];

void func(int now){
    w[now]=1;
    while(now<=n && m[now]==0){ w[now]=1; now++;}
    if(now>n) return;
    int nxt=m[now];
    for(int i=nxt; i>now; i--){
        func(i);
        if(m[i]) break;
    }
}

int main(){
    scanf("%d%d%d", &n, &a, &b);
    int x, y;
    for(int i=1; i<=b; i++){
        scanf("%d%d", &x, &y);
        m[x]=y;
    }
    func(1);
    if(w[a]) printf("YES\n");
    else printf("NO\n");
    return 0;
}

