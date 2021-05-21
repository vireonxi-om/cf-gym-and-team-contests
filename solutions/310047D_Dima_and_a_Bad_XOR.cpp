// Problem: Dima and a Bad XOR
// URL: https://codeforces.com/gym/310047/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, ans[510];
vector<int> p[510][15][2];

int main(){
    scanf("%d%d", &n, &m);
    int num, t;
    bool can=false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &num);
            t=0;
            while(num>0){
                p[i][t][num%2].push_back(j);
                num/=2;
                t++;
            }
            for(int k=t; k<=12; k++) p[i][k][0].push_back(j);
        }
    }
    for(int i=0; i<=12; i++){
        int cnt1=0;
        for(int j=1; j<=n; j++){
            if(!p[j][i][0].empty()) ans[j]=(*p[j][i][0].begin());
            else {ans[j]=(*p[j][i][1].begin()); cnt1++;}
        }
        if(cnt1%2==1) can=true;
        else{
            for(int j=1; j<=n; j++){
                if(!p[j][i][0].empty() && !p[j][i][1].empty()) {
                    ans[j]=(*p[j][i][1].begin());
                    can=true; break;
                }
            }
        }
        if(can) break;
    }
    if(can) {
        printf("TAK\n");
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        printf("\n");
    }
    else printf("NIE\n");
    return 0;
}

