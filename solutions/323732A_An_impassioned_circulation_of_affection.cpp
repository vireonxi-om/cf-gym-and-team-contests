// Problem: An impassioned circulation of affection
// URL: https://codeforces.com/gym/323732/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[1600][30], ans[1600][30];
char s[1600];

int main(){
    scanf("%d%s", &n, s+1);
    for(int i=0; i<26; i++){
        char c='a'+i;
        for(int j=1; j<=n; j++){
            if(s[j]==c) a[j][i]=a[j-1][i];
            else a[j][i]=a[j-1][i]+1;
        }
        for(int num=1; num<=n; num++){
            int t2=1;
            for(int t1=1; t1<=n-num+1; t1++){
                t2=max(t2, t1);
                while(t2<n && a[t2+1][i]-a[t1-1][i]<=num) t2++;
                ans[num][i]=max(ans[num][i], t2-t1+1);
                if(t2==n) break;
            }
        }
    }
    int q, t;
    char c;
    scanf("%d", &q);
    while(q--){
        scanf("%d%c%c", &t, &c, &c);
        printf("%d\n", ans[t][c-'a']);
    }
    return 0;
}
