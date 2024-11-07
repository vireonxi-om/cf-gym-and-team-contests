// Problem: Love Rescue
// URL: https://codeforces.com/gym/316837/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, fa[30];
char a[110000], b[110000];
vector<int> f[30];
vector<pair<int, int>> ans;

int find(int u){
    int t=u;
    while(fa[t]!=t) t=fa[t];
    return t;
}

int main(){
    scanf("%d", &n);
    scanf("%s%s", a+1, b+1);
    for(int i=0; i<26; i++) fa[i]=i;
    for(int i=1; i<=n; i++){
        if(a[i]!=b[i]){
            int af=find(a[i]-'a');
            int bf=find(b[i]-'a');
            if(af!=bf) fa[bf]=af;
        }
    }
    for(int i=0; i<26; i++){
        fa[i]=find(i);
        f[fa[i]].push_back(i);
    }
    for(int i=0; i<=26; i++){
        if(f[i].size()>=2){
            for(int j=0; j<=f[i].size()-2; j++){
                ans.push_back(make_pair(f[i][j], f[i][j+1]));
            }
        }
    }
    printf("%d\n", ans.size());
    for(auto x:ans){
        printf("%c %c\n", x.first+'a', x.second+'a');
    }
    return 0;
}
