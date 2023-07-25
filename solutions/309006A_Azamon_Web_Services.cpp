// Problem: Azamon Web Services
// URL: https://codeforces.com/gym/309006/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ls, lc;
char s[5100], c[5100];

void solve(){
    scanf("%s%s", s+1, c+1);
    ls=strlen(s+1); lc=strlen(c+1);
    bool conti=true;
    for(int i=1; i<=ls; i++){
        if(s[i]>'A'){
            char now='Z'+1; int t;
            for(int j=ls; j>i; j--){
                if(s[j]<now){
                    now=s[j];
                    t=j;
                }
            }
            if(s[i]>now){
                s[t]=s[i]; s[i]=now;
                break;
            }
        }
    }
    int pos=1;
    while(pos<=min(ls, lc) && s[pos]==c[pos]) pos++;
    bool can;
    if(pos>lc) can=false;
    else if(pos>ls) can=true;
    else if(s[pos]<c[pos]) can=true;
    else can=false;
    if(can) printf("%s\n", s+1);
    else printf("---\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
