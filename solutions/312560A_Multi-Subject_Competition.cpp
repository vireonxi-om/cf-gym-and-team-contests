// Problem: Multi-Subject Competition
// URL: https://codeforces.com/gym/312560/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, sum[110000], pre[110000];
vector<int> sub[110000];

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        int s, num;
        scanf("%d%d", &s, &num);
        sub[s].push_back(num);
    }
    for(int i=1; i<=m; i++){
        sort(sub[i].begin(), sub[i].end(), greater<>());
        int len=sub[i].size();
        pre[0]=0;
        for(int j=0; j<len; j++){
            pre[j+1]=pre[j]+sub[i][j];
            if(pre[j+1]>0) sum[j+1]+=pre[j+1];
        }
    }
    int result=0;
    for(int i=1; i<=n; i++) result=max(result, sum[i]);
    printf("%d\n", result);
    return 0;
}