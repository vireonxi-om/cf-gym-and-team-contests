// Problem: Count Subrectangles
// URL: https://codeforces.com/gym/303728/problem/J
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, result;
int a[41000], b[41000];

int main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    int cnt=0;
    map<int, int> cnta;
    map<int, int> cntb;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if(a[i]==1) {
            cnt++;
            if(i==n) cnta[cnt]++;
        }
        else if(a[i]==0 && cnt>0){
            cnta[cnt]++; cnt=0;
        }
    }
    cnt=0;
    for(int i=1; i<=m; i++){
        scanf("%d", &b[i]);
        if(b[i]==1) {
            cnt++;
            if(i==m) cntb[cnt]++;
        }
        else if(b[i]==0 && cnt>0){
            cntb[cnt]++; cnt=0;
        }
    }
    for(auto [xa, ya]: cnta){
        for(auto [xb, yb]: cntb){
            for(int i=xa; i>=1; i--){
                if(k%i==0 && k/i<=xb){
                    result+=(ll)(xa-i+1)*(xb-k/i+1)*ya*yb;
                }
                else if(k/i>xb) break;
            }
        }
    }
    printf("%lld", result);
}
