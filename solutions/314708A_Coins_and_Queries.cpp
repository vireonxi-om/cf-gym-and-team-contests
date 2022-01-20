// Problem: Coins and Queries
// URL: https://codeforces.com/gym/314708/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, q, cnt[35], temp[35];

int main(){
    int num;
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        int t=-1;
        while(num){
            num/=2;
            t++;
        }
        cnt[t]++;
    }
    for(int i=1; i<=q; i++){
        for(int i=0; i<35; i++) temp[i]=0;
        scanf("%d", &num);
        int t=0;
        while(num){
            temp[t]=num%2;
            num/=2;
            t++;
        }
        int ans=0;
        bool can=true;
        for(int i=32; i>=0; i--){
            if(temp[i]==0) continue;
            if(i==0 && cnt[i]<temp[i]) can=false;
            if(cnt[i]>=temp[i]){
                ans+=temp[i];
            }
            else{
                ans+=cnt[i];
                temp[i-1]+=2*(temp[i]-cnt[i]);
            }
        }
        if(can) printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}
