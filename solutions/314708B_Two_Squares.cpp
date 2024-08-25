// Problem: Two Squares
// URL: https://codeforces.com/gym/314708/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int xa, xb, ya, yb;

int main() {
    int t1, t2, t3, t4;
    scanf("%d%d%d%d%d%d%d%d", &xa, &ya, &t1, &t2, &xb, &yb, &t3, &t4);
    if (xa > xb) swap(xa, xb);
    if (ya > yb) swap(ya, yb);
    int xmin=200, ymin=200, xmax=-200, ymax=-200;
    for(int i=1; i<=8; i++){
        scanf("%d", &t1);
        if(i%2==1){
            xmax=max(xmax, t1);
            xmin=min(xmin, t1);
        }
        else {
            ymax=max(ymax, t1);
            ymin=min(ymin, t1);
        }
    }
    bool can = false;
    int a=(xmax-xmin)/2, y0=(ymin+ymax)/2;
    for(int i=0; i<=a; i++){
        int x=xmin+i, y=y0-i;
        for(int j=0; j<=a; j++){
            if(x+j<=xb && x+j>=xa && y+j<=yb && y+j>=ya) can=true;
        }
    }
    if(can) printf("YES\n");
    else printf("NO\n");
    return 0;
}