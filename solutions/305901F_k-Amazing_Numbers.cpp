// Problem: k-Amazing Numbers
// URL: https://codeforces.com/gym/305901/problem/F
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, a[310000], d[310000];

void solve(){
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        d[num]=max(d[num], i-a[num]);
        a[num]=i;
    }
    map<int, int> cnt;
    map<int, int> ::iterator it;
    for(int i=1; i<=n; i++){
        if(a[i]!=0) d[i]=max(d[i], n+1-a[i]);
    }
    for(int i=1; i<=n; i++){
        if(d[i]!=0){
            if(cnt.count(d[i]))
                cnt[d[i]]=min(i, cnt[d[i]]);
            else cnt[d[i]]=i;
        }
    }
    it=cnt.begin();
    int value=(*it).second;
    for(int k=1; k<=n; k++){
        while((*it).first<=k && it!=cnt.end()){
            value=min(value, (*it).second);
            it++;
        }
        if(it==cnt.begin()) printf("-1 ");
        else {
            it--;
            printf("%d ", value);
        }
    }
    printf("\n");

}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

