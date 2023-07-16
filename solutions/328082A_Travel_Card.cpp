// Problem: Travel Card
// URL: https://codeforces.com/gym/328082/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> a;
ll dp[110000];

int main(){
    scanf("%d", &n);
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        a.push_back(num);
        int t=lower_bound(a.begin(), a.end(), num)-a.begin();
        dp[i]=dp[t]+20;
        t=lower_bound(a.begin(), a.end(), num-89)-a.begin();
        dp[i]=min(dp[i], dp[t]+50);
        t=lower_bound(a.begin(), a.end(), num-1439)-a.begin();
        dp[i]=min(dp[i], dp[t]+120);
        printf("%lld\n", dp[i]-dp[i-1]);
    }
    return 0;
}
