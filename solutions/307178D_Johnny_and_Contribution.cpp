// Problem: Johnny and Contribution
// URL: https://codeforces.com/gym/307178/problem/D
// Rating: 1700
// Tags: none (gym/team contest)
// Language: C++14 (GCC 6-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, now[510000], col[510000];
vector<int> b[510000], p[510000];

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        p[x].push_back(y);
        p[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        int num; scanf("%d", &num);
        b[num].push_back(i);
        now[i]=0;
    }
    bool can=true;
    for(int i=1; i<=n; i++){
        for(auto x:b[i]){
            for(auto y:p[x]) col[now[y]]=x;
            int j=1;
            while(col[j]==x) j++;
            if(j!=i){
                can=false; break;
            }
            else now[x]=i;
        }
    }
    if(can){
        for(int i=1; i<=n; i++){
            for(auto x:b[i]) printf("%d ", x);
        }
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}

