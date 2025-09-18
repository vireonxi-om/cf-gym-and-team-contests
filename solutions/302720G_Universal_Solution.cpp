// Problem: Universal Solution
// URL: https://codeforces.com/gym/302720/problem/G
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
char a[210000], result;
int r, s, p;

void solve(){
    scanf("%s", &a);
    int l=strlen(a);
    r=0; s=0; p=0;
    for(int i=0; i<l; i++){
        if (a[i]=='R') r++;
        else if(a[i]=='S') s++;
        else p++;
    }
    if(r>=s && r>=p) result='P';
    else if(s>=r && s>=p) result='R';
    else result='S';
    for(int i=0; i<l; i++)
        printf("%c", result);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
