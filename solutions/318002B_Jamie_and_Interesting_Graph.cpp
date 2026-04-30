// Problem: Jamie and Interesting Graph
// URL: https://codeforces.com/gym/318002/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m;
vector<pair<int, pair<int, int>>> ans;
int main(){
    scanf("%d%d", &n, &m);
    int num;
    for(num=n; ;num++){
        bool can=true;
        for(int j=2; j<=sqrt(num); j++) if(num%j==0){ can=false; break;}
        if(can) break;
    }
    for(int i=1; i<n-1; i++) ans.push_back(make_pair(1, make_pair(i, i+1)));
    ans.push_back(make_pair(num-n+2, make_pair(n-1, n)));
    m-=(n-1);
    for(int i=1; i<n-1; i++){
        if(m==0) break;
        for(int j=i+2; j<=n; j++){
            if(m==0) break;
            ans.push_back(make_pair(2*num, make_pair(i, j)));
            m--;
        }
    }
    printf("%d %d\n", num, num);
    for(auto x:ans){
        printf("%d %d %d\n", x.second.first, x.second.second, x.first);
    }
}
