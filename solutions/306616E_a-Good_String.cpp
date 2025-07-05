// Problem: a-Good String
// URL: https://codeforces.com/gym/306616/problem/E
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, result;
char a[200000];

int cal(int i, int n, char ch){
    n/=2;
    if(n==0){
        if(a[i]!=ch) return 1;
        else return 0;
    }
    int cnt1=0, cnt2=0;
    for(int k=i; k<i+n; k++) if(a[k]==ch) cnt1++;
    for(int k=i+n; k<i+2*n; k++) if(a[k]==ch) cnt2++;
    int r1=n-cnt1+cal(i+n, n, ch+1);
    int r2=n-cnt2+cal(i, n, ch+1);
    return min(r1, r2);
}

void solve(){
    scanf("%d", &n);
    scanf("%s", &a);
    result=cal(0, n, 'a');
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

