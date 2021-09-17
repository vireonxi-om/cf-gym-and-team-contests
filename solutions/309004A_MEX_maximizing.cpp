// Problem: MEX maximizing
// URL: https://codeforces.com/gym/309004/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q, x, num, ans[410000], cnt[410000];

int main(){
    scanf("%d%d", &q, &x);
    int now=0;
    for(int i=1; i<=q; i++){
        scanf("%d", &num);
        int t=num%x;
        if((ll)cnt[t]*x+t<410000) ans[(ll)cnt[t]*x+t]=1;
        cnt[t]++;
        while(now<410000 && ans[now]==1) now++;
        printf("%d\n", now);
    }
}

