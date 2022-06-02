// Problem: Alarm Clock
// URL: https://codeforces.com/gym/320372/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, k, t[1100000];

int main(){
    scanf("%d%d%d", &n, &m, &k);
    int num, maxi=0;
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        maxi=max(maxi, num);
        t[num]=1;
    }
    int tot=0, cnt=0;
    for(int i=1; i<=maxi; i++){
        tot+=t[i];
        if(tot-t[max(0, i-m)]>=k){
            tot--;
            cnt++;
        }
        t[i]=tot;
    }
    printf("%d\n", cnt);
}
