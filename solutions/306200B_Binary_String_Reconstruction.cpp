// Problem: Binary String Reconstruction
// URL: https://codeforces.com/gym/306200/problem/B
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
char s[110000], w[110000];
int x, l;

void solve(){
    memset(w, '0', sizeof(w));
    scanf("%s%d", &s, &x);
    l=strlen(s);
    for(int i=0; i<l; i++){
        if(s[i]=='1'){
            bool can=false;
            if(i>=x){
                if(i>=2*x){
                    if(s[i-2*x]=='1'){
                        can=true;
                        w[i-x]='1';
                    }
                }
                else{
                    can=true;
                    w[i-x]='1';
                }
            }
            if(i<=l-1-x){
                if(i<=l-1-2*x){
                    if(s[i+2*x]=='1'){
                        can=true;
                        w[i+x]='1';
                    }
                }
                else{
                    can=true;
                    w[i+x]='1';
                }
            }
            if(!can) {
                printf("-1\n");
                return;
            }
        }
    }
    for(int i=0; i<l; i++) printf("%c", w[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
