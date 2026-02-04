// Problem: Program
// URL: https://codeforces.com/gym/329908/problem/B
// Rating: 1700
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, maxi[1100000], mini[1100000], now[210000];
char s[210000];

void update(int l, int r, int pos, int id, int val){
    if(l==r){ maxi[pos]=val; mini[pos]=val; return; }
    int mid=(l+r)/2;
    if(mid<id) update(mid+1, r, pos*2+1, id, val);
    else update(l, mid, pos*2, id, val);
    maxi[pos]=max(maxi[pos*2], maxi[pos*2+1]);
    mini[pos]=min(mini[pos*2], mini[pos*2+1]);
}

int getmax(int l, int r, int pos, int a, int b){
    if(l==a && r==b) return maxi[pos];
    int mid=(l+r)/2;
    if(mid<a) return getmax(mid+1, r, pos*2+1, a, b);
    else if(mid>=b) return getmax(l, mid, pos*2, a, b);
    else return max(getmax(l, mid, pos*2, a, mid), getmax(mid+1, r, pos*2+1, mid+1, b));
}

int getmin(int l, int r, int pos, int a, int b){
    if(l==a && r==b) return mini[pos];
    int mid=(l+r)/2;
    if(mid<a) return getmin(mid+1, r, pos*2+1, a, b);
    else if(mid>=b) return getmin(l, mid, pos*2, a, b);
    else return min(getmin(l, mid, pos*2, a, mid), getmin(mid+1, r, pos*2+1, mid+1, b));
}

void solve(){
    scanf("%d%d%s", &n, &m, s+1);
    int num=0; update(0, n, 1, 0, num);
    now[0]=0;
    for(int i=1; i<=n; i++){
        if(s[i]=='-') num--;
        else num++;
        update(0, n, 1, i, num);
        now[i]=num;
    }
    int l, r, m1, m2, u, d;
    while(m--){
        scanf("%d%d", &l, &r);
        u=getmax(0, n, 1, 0, l-1);
        d=getmin(0, n, 1, 0, l-1);
        if(r<n){
            m1=getmax(0, n, 1, r+1, n)-now[r];
            m2=getmin(0, n, 1, r+1, n)-now[r];
        }
        else{ m1=0; m2=0;}
        u=max(u, m1+now[l-1]);
        d=min(d, m2+now[l-1]);
        printf("%d\n", u-d+1);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


