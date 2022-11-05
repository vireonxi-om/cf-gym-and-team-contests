// Problem: Five-In-a-Row
// URL: https://codeforces.com/gym/323731/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
char a[15][15];


int main(){
    for(int i=1; i<=10; i++){
        scanf("%s", a[i]+1);
    }
    bool yes=false;
    for(int i=1; i<=10; i++){
        for(int j=1; j<=6; j++){
            bool can=true;
            int cnt=0;
            for(int t=j; t<j+5; t++){
                if(a[i][t]=='.') cnt++;
                else if(a[i][t]=='O') can=false;
            }
            if(can && cnt==1){ yes=true; }
        }
    }
    for(int i=1; i<=10; i++){
        for(int j=1; j<=6; j++){
            bool can=true;
            int cnt=0;
            for(int t=j; t<j+5; t++){
                if(a[t][i]=='.') cnt++;
                else if(a[t][i]=='O') can=false;
            }
            if(can && cnt==1){ yes=true; }
        }
    }
    for(int t=5; t>=-5; t--){
        int m=min(6, 6+t);
        for(int i=max(1, t+1); i<=m; i++){
            bool can=true;
            int cnt=0;
            for(int l=0; l<5; l++){
                if(a[i+l][i-t+l]=='.') cnt++;
                else if(a[i+l][i-t+l]=='O') can=false;
            }
            if(can && cnt==1){ yes=true; }
        }
    }
    for(int t=6; t<=16; t++){
        for(int i=min(10, t-1); i>=max(5, t-6); i--){
            bool can=true;
            int cnt=0;
            for(int l=0; l<5; l++){
                if(a[i-l][t-i+l]=='.') cnt++;
                else if(a[i-l][t-i+l]=='O') can=false;
            }
            if(can && cnt==1){ yes=true; }
        }
    }
    if(yes) printf("YES\n");
    else printf("NO\n");
    return 0;
}
