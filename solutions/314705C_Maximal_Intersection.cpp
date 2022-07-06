// Problem: Maximal Intersection
// URL: https://codeforces.com/gym/314705/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
vector<pair<int, int>> a;

int main(){
    scanf("%d", &n);
    int l1=0, r1=2e9, lpos, rpos;
    for(int i=1; i<=n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        a.push_back(make_pair(l, r));
        if(l>=l1){
            l1=l;
            lpos=i;
        }
        if(r<=r1){
            r1=r;
            rpos=i;
        }
    }
    int result=0, l=0, r=2e9;
    for(int i=0; i<n; i++){
        if(i==lpos-1) continue;
        else{ r=min(r, a[i].second); l=max(l, a[i].first);}
    }
    result=max(result, r-l);
    l=0, r=2e9;
    for(int i=0; i<n; i++){
        if(i==rpos-1) continue;
        else{ r=min(r, a[i].second); l=max(l, a[i].first);}
    }
    result=max(result, r-l);
    printf("%d\n", result);
    return 0;
}
