// Problem: A - Rank Riana and One Punch
// URL: https://codeforces.com/gym/102556/problem/A
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char a[110];


int main(){
    scanf("%s", a+1);
    n=strlen(a+1);
    int cnt=0, m=0;
    for(int i=1; i<=n; i++){
        int now=0;
        while(i<=n && a[i]=='.'){
            now++; i++; cnt++;
        }
        m=max(m, now);
    }
    int t=0;
    for(int i=1; i<=n; i++){
        if(a[i]=='X'){
            t++;
            while(i<=n && a[i+1]=='X') i++;
        }
    }
    if(m && a[1]=='X' && a[n]=='X') t--;
    if(t && a[1]=='.' && a[n]=='.'){
        int now=0;
        for(int i=1; i<=n; i++) {
            if(a[i]=='X') break;
            now++;
        }
        for(int i=n; i>=1; i--) {
            if(a[i]=='X') break;
            now++;
        }
        m=max(m, now);
    }
    if(t<2) printf("0\n");
    else printf("%d\n", cnt-m);
    return 0;
}

