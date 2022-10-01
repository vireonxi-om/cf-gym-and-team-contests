// Problem: Unlucky 7
// URL: https://codeforces.com/gym/312858/problem/C
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;

int main(){
    scanf("%d", &n);
    int cnt=0;
    for(int i=1; i<=n; i++){
        bool o=false, d=false;
        int now=i;
        while(now>0){
            int num=now%10;
            if(num==7) d=true;
            now/=10;
        }
        now=i;
        while(now>0){
            int num=now%8;
            if(num==7) o=true;
            now/=8;
        }
        if(!o && !d) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
