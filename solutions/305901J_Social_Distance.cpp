// Problem: Social Distance
// URL: https://codeforces.com/gym/305901/problem/J
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k, a[210000];

void solve(){
    scanf("%d%d", &n, &k);
    int num, last1=0, cnt=0;
    for(int i=1; i<=n; i++){
        scanf("%1d", &num);
        if(num==1){
            if(last1==0){
                cnt+=(i-1)/(k+1);
            }
            else{
                int t=(i-last1)/(k+1)-1;
                if(t>0) cnt+=t;
            }
            last1=i;
        }
        else if(num==0 && i==n){
            if(last1==0) cnt+=(n-1)/(k+1)+1;
            else cnt+=(n-last1)/(k+1);
        }
    }
    printf("%d\n", cnt);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

