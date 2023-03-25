// Problem: Cutting Out
// URL: https://codeforces.com/gym/312560/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k, s[210000], cnt[210000];
vector<int> ans;

bool can(int t){
    ans.clear();
    for(int i=0; i<200001; i++){
        int num=min(cnt[i]/t, k-int(ans.size()));
        for(int j=1; j<=num; j++){
            ans.push_back(i);
        }
    }
    return ans.size()==k;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &s[i]);
        cnt[s[i]]++;
    }
    int l=0, r=n;
    while(r-l>1){
        int mid=(l+r)/2;
        if(can(mid)) l=mid;
        else r=mid;
    }
    if(!can(r)) can(l);
    for(auto x:ans) printf("%d ", x);
    printf("\n");
}
