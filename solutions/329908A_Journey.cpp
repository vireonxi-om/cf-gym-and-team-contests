// Problem: Journey
// URL: https://codeforces.com/gym/329908/problem/A
// Rating: 1700
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, l[310000], r[310000];
char s[310000];

void solve(){
    scanf("%d%s", &n, s+1);
    int now=n;
    char last=s[n];
    if(last=='R') r[n-1]=n;
    else r[n-1]=n-1;
    r[n]=n;
    for(int i=n-1; i>0; i--){
        if(s[i]==last){
            if(s[i]=='R') r[i-1]=i;
            else r[i-1]=i-1;
            now=i;
        }
        else{
            if(s[i]=='R') r[i-1]=now;
            else r[i-1]=i-1;
            last=s[i];
        }
    }
    last=s[1]; now=0;
    if(last=='L') l[1]=0; else l[1]=1;
    l[0]=0;
    for(int i=2; i<=n; i++){
        if(s[i]==last){
            if(s[i]=='L') l[i]=i-1;
            else l[i]=i;
            now=i-1;
        }
        else{
            if(s[i]=='L') l[i]=now;
            else l[i]=i;
            last=s[i];
        }
    }
    for(int i=0; i<=n; i++){
        printf("%d ", r[i]-l[i]+1);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


