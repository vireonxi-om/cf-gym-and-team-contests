// Problem: Blocks on Grid
// URL: https://codeforces.com/gym/312858/problem/B
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int h, w, a[110][110];

int main(){
    scanf("%d%d", &h, &w);
    int m=110, sum=0;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            scanf("%d", &a[i][j]);
            m=min(m, a[i][j]);
            sum+=a[i][j];
        }
    }
    printf("%d\n", sum-m*h*w);
    return 0;
}
