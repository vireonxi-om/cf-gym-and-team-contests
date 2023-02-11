// Problem: Short Task
// URL: https://codeforces.com/gym/329456/problem/B
// Rating: 1700
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=11000000;
int mind[MAX], ans[MAX];
vector<int> primes;
vector<pair<int, int>> num;

ll power(ll a, ll b){
    ll result=1;
    while(b){
        result*=a;
        b--;
    }
    return result;
}

int main(){
    for(int i=2; i<MAX; i++){
        if(mind[i] == 0){
            primes.emplace_back(i);
            mind[i]=i;
        }
        for(auto x: primes){
            if(x>mind[i] || x*i>=MAX) break;
            mind[x*i]=x;
        }
    }
    for(int i=1; i<MAX; i++){
        num.clear();
        int cnt=0, last=0, x=i;
        while(x>1){
            int p=mind[x];
            if(last==p) cnt++;
            else{
                num.push_back(make_pair(last, cnt));
                last=p; cnt=1;
            }
            x/=p;
        }
        num.push_back(make_pair(last, cnt));
        ll tot=1;
        for(auto t:num){
            ll sum=0;
            for(int k=0; k<=t.second; k++) sum+=power(t.first, k);
            tot*=sum;
        }
        if(tot<MAX && ans[tot]==0) ans[tot]=i;
    }
    int t, c;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &c);
        if(ans[c]==0) printf("-1\n");
        else printf("%d\n", ans[c]);
    }
    return 0;
}

