// Problem: Square-free division (easy version)
// URL: https://codeforces.com/gym/329456/problem/C
// Rating: 1700
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=11000000;
int n, k, a[210000], mind[MAX];
vector<int> primes;
set<pair<int, int>> s;

void solve(){
    s.clear();
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) a[i]=n;
    int num, id;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        int ans=1, cnt=0, last=0;
        while(num>1){
            int p=mind[num];
            if(last==p) cnt++;
            else{
                if(cnt%2) ans*=last;
                last=p; cnt=1;
            }
            num/=p;
        }
        if(cnt%2) ans*=last;
        auto it=s.lower_bound(make_pair(ans, 0));
        if(it==s.end() || (*it).first>ans){
            s.insert(make_pair(ans, i));
        }
        else{
            a[(*it).second]=i-1;
            s.erase(it);
            s.insert(make_pair(ans, i));
        }
    }
    int now=n, tot=0;
    for(int i=1; i<=n; i++){
        now=min(now, a[i]);
        if(now==i){ tot++; now=n;}
    }
    printf("%d\n", tot);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=2; i<MAX; i++){
        if(mind[i] == 0){
            primes.push_back(i);
            mind[i]=i;
        }
        for(auto x: primes){
            if(x>mind[i] || x*i>=MAX) break;
            mind[x*i]=x;
        }
    }
    while(t--) solve();
    return 0;
}

