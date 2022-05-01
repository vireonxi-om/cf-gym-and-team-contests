// Problem: Cameras
// URL: https://codeforces.com/gym/101291/problem/D
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, m, a[110000], t[1100000];

void update(int l, int r, int now, int id, int val){
    if(l==r){ t[now]=val; return;}
    int mid=(l+r)/2;
    if(id<=mid) update(l, mid, now*2, id, val);
    else update(mid+1, r, now*2+1, id, val);
    t[now]=t[now*2]+t[now*2+1];
}

int cal(int l, int r, int now, int x, int y){
    if(l==x && r==y) return t[now];
    int mid=(l+r)/2;
    if(mid<x) return cal(mid+1, r, now*2+1, x, y);
    else if(mid>=y) return cal(l, mid, now*2, x, y);
    else return cal(l, mid, now*2, x, mid)+cal(mid+1, r, now*2+1, mid+1, y);
}

int main(){
    scanf("%d%d%d", &n, &k, &m);
    int num;
    a[1]=1; a[2]=1;
    update(1, n+2, 1, 1, 1);
    update(1, n+2, 1, 2, 1);
    for(int i=1; i<=k; i++){
        scanf("%d", &num);
        a[num+2]=1;
        update(1, n+2, 1, num+2, 1);
    }
    int cnt=0;
    for(int i=1; i<=n+2-m; i++){
        if(a[i]==0) continue;
        if(cal(1, n+2, 1, i+1, i+m)<2){
            cnt++;
            a[i+m]=1;
            update(1, n+2, 1, i+m, 1);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
