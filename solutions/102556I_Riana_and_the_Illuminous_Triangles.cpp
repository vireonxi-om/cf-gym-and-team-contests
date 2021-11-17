// Problem: Riana and the Illuminous Triangles
// URL: https://codeforces.com/gym/102556/problem/I
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[310][310][310];
struct point{
    int x; int y;
    int operator * (const point &rhs) const{
        return x*rhs.y-y*rhs.x;
    }
    point operator - (const point &rhs) const{
        return {x-rhs.x, y-rhs.y};
    }
}a[310];
bitset<310> l[310][310], r[310][310];


int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d%d", &a[i].x, &a[i].y);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i==k || i==j || j==k) continue;
                if((a[j]-a[i])*(a[k]-a[i])>0) l[i][j].set(k);
                else r[i][j].set(k);
            }
        }
    }
    ll ans=0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int t=(l[i][j] & l[j][k] & l[k][i]).count() + (r[i][j] & r[j][k] & r[k][i]).count();
                ans+=t*(t-1)*(t-2)/6;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}


