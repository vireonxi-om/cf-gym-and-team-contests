// Problem: Good String
// URL: https://codeforces.com/gym/306200/problem/G
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, cnt[10], result;
char s[210000];

void solve(){
    int max1=0;
    result=0;
    for(int i=0; i<10; i++) cnt[i]=0;
    scanf("%s", &s);
    n=strlen(s);
    for(int i=0; i<n; i++){
        cnt[s[i]-'0']++;
        max1=max(max1, cnt[s[i]-'0']);
    }
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            int now=-1, tot=0;
            for(int k=0; k<n; k++){
                if(s[k]-'0'==i){
                    if(tot==0 || now==j){
                        tot++; now=i;
                    }
                }
                else if(s[k]-'0'==j){
                    if(tot==0 || now==i){
                        tot++; now=j;
                    }
                }
            }
            result=max(result, tot-tot%2);
        }
    }
    result=max(result, max1);
    printf("%d\n", n-result);
}
int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

