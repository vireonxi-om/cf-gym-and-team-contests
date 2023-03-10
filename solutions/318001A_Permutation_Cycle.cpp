// Problem: Permutation Cycle
// URL: https://codeforces.com/gym/318001/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a, b, ans[1100000];


int main(){
    scanf("%d%d%d", &n, &a, &b);
    bool can=false;
    if(a==1 || b==1){
        for(int i=1; i<=n; i++) ans[i]=i;
        can=true;
    }
    else{
        int ta, tb;
        for(ta=0; ta*a<=n; ta++){
            if((n-ta*a)==0 || (n-ta*a)%b==0){
                tb=(n-ta*a)/b;
                can=true;
                break;
            }
        }
        if(can){
            int t=ta;
            for(int i=1; t; i+=a){
                ans[i]=i+a-1;
                for(int j=i+1; j<i+a; j++) ans[j]=j-1;
                t--;
            }
            for(int i=1+a*ta; tb; i+=b){
                ans[i]=i+b-1;
                for(int j=i+1; j<i+b; j++) ans[j]=j-1;
                tb--;
            }
        }
    }
    if(can){
        for(int i=1; i<=n; i++) printf("%d ", ans[i]);
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}
