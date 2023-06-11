// Problem: Baby Ehab Partitions Again
// URL: https://codeforces.com/gym/329456/problem/A
// Rating: 1700
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[210000], sum;

int main(){
    dp[0]=1;
    scanf("%d", &n);
    int num, pos, m=100;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        for(int j=200000; j>=0; j--){
            if(!dp[j]) continue;
            dp[j+num]=1;
        }
        sum+=num;
        int cnt=0;
        while(num){
            if(num%2) break;
            num/=2; cnt++;
        }
        if(cnt<m){ m=cnt; pos=i;}
    }
    bool can=true;
    if(sum%2) can=false;
    else if(dp[sum/2]==0) can=false;
    if(!can) printf("0\n");
    else printf("1\n%d\n", pos);
    return 0;
}

