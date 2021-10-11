// Problem: Optimal Subsequences (Easy Version)
// URL: https://codeforces.com/gym/309196/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[110], b[110], ans[110];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        b[i]=a[i];
    }
    sort(b+1, b+n+1);
    scanf("%d", &m);
    while(m--){
        int k, p, last=-1, cnt;
        vector<int> num;
        for(int i=1; i<=n; i++) ans[i]=0;
        scanf("%d%d", &k, &p);
        for(int i=n; i>n-k; i--){
            if(i==1 || b[i-1]!=b[i]) num.push_back(b[i]);
            else if(i==n-k+1){
                last=b[i];
                for(cnt=1; cnt<k; cnt++){
                    if(b[i+cnt]!=last) break;
                }
            }
        }
        for(auto x:num) {
            for(int i=1; i<=n; i++){
                if(a[i]==x) ans[i]=1;
            }
        }
        if(last!=-1){
            for(int i=1; i<=n && cnt>0; i++){
                if(a[i]==last) {ans[i]=1; cnt--;}
            }
        }
        for(int i=1; i<=n; i++){
            if(ans[i]==1) p--;
            if(p==0){ printf("%d\n", a[i]); break;}
        }
    }
    return 0;
}
