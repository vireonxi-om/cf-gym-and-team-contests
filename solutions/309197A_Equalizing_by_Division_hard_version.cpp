// Problem: Equalizing by Division (hard version)
// URL: https://codeforces.com/gym/309197/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, a[210000], b[210000][30];

void cnt(int num){
    int t=0;
    while(num>0){
        b[num][t]++;
        num/=2; t++;
    }
    b[num][t]++;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) {scanf("%d", &a[i]); cnt(a[i]);}
    int result=1e9;
    for(int i=0; i<210000; i++){
        int sum=k, tot=0, pos=0, num=0;
        bool can=false;
        for(int j=0; j<30; j++){
            sum-=b[i][j];
            if(sum<=0){
                pos=j; num=b[i][j]+sum;
                can=true; break;
            }
        }
        for(int j=0; j<pos; j++) tot+=b[i][j]*j;
        tot+=pos*num;
        if(can) result=min(result, tot);
    }
    printf("%d\n", result);
    return 0;
}
