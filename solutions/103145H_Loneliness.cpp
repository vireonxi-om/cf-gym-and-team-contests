// Problem: Loneliness
// URL: https://codeforces.com/gym/103145/problem/H
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k;
vector<int> a;
string ans;

void solve(){
    a.clear(); ans.clear();
    scanf("%lld", &k);
    int cnt=0;
    while(k){
        if(k%2) cnt++;
        a.push_back(k%2);
        k/=2;
    }
    if(a[0]==1){
        printf("-1\n");
        return;
    }
    reverse(a.begin(), a.end());
    auto it=a.end(); it--; a.erase(it);
    int t=a.size();
    ans+="DRUL";
    for(int i=1; i<100-t; i++) ans+='D';
    for(int i=1; i<=100-cnt-1; i++) ans+="DRRUL";
    for(auto x:a){
        if(x==1) ans+="DR";
        else ans+='D';
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    scanf("%d%d", &t, &n);
    while(t--) solve();
    return 0;
}

