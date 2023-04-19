// Problem: Constructing the Array
// URL: https://codeforces.com/gym/307718/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[210000];

struct cmp{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b){
        int lena = a.second-a.first+1;
        int lenb = b.second-b.first+1;
        if(lena == lenb) return a.first < b.first;
        else return lena>lenb;
    }
};

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) a[i]=0;
    set<pair<int, int>, cmp> seg;
    seg.insert(make_pair(1, n));
    for(int i=1; i<=n; i++){
        pair<int, int> now = *seg.begin();
        seg.erase(seg.begin());
        int mid=(now.first+now.second)/2;
        a[mid]=i;
        if(now.first<mid) seg.insert(make_pair(now.first, mid-1));
        if(now.second>mid) seg.insert(make_pair(mid+1, now.second));
    }
    for(int i=1; i<=n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
