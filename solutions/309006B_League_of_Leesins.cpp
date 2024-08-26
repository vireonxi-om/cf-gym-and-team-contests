// Problem: League of Leesins
// URL: https://codeforces.com/gym/309006/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, used[110000], ans[110000];
vector<int> p[110000];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n-2; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        p[a].push_back(b); p[a].push_back(c);
        p[b].push_back(a); p[b].push_back(c);
        p[c].push_back(a); p[c].push_back(b);
    }
    for(int i=1; i<=n; i++){
        if(p[i].size()==2){
            ans[1]=i; used[i]=1;
            for(auto x:p[i]) if(p[x].size()==4) ans[2]=x;
            used[ans[2]]=1;
            break;
        }
    }
    for(int i=1; i<=n-2; i++){
        for(auto x:p[ans[i]]){
            if(used[x]==0){
                ans[i+2]=x;
                used[x]=1;
                break;
            }
        }
    }
    for(int i=1; i<=n; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
