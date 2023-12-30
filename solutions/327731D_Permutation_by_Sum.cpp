// Problem: Permutation by Sum
// URL: https://codeforces.com/gym/327731/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, l, r, s, a[510], b[510];
vector<int> ans;

void solve(){
    scanf("%d%d%d%d", &n, &l, &r, &s);
    for(int i=1; i<=n; i++){ a[i]=0; b[i]=0;}
    int t=r-l+1;
    int sum;
    bool can=false;
    for(int i=1; i<=n-t+1; i++){
        sum=0;
        ans.clear();
        for(int j=i; j<=i+t-1; j++){ sum+=j; ans.push_back(j);}
        if(sum>=s){ can=true; break;}
    }
    if(sum-s>0 && ans[0]==1) can=false;
    if(can){
        for(int i=0; i<sum-s; i++) ans[i]--;
        int now=l;
        for(auto x: ans){ a[x]=1; b[now]=x; now++;}
        now=1;
        for(int i=1; i<=n; i++){
            if(i<=r && i>=l) continue;
            while(a[now]) now++;
            b[i]=now; now++;
        }
        for(int i=1; i<=n; i++) printf("%d ", b[i]); printf("\n");
    }
    else printf("-1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
