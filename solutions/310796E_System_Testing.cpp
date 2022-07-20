// Problem: System Testing
// URL: https://codeforces.com/gym/310796/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k, t[1100], st[1100], a[200000], comp, result;
priority_queue<int> p;

int main(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d", &t[i]);
    for(int i=1; i<=min(n, k); i++){ p.push(-t[i]); st[i]=1; }
    int now=k+1, end;
    while(comp<n){
        int top=p.top(); p.pop();
        int cnt=1;
        while(!p.empty() && p.top()==top){
            p.pop(); cnt++;
        }
        comp+=cnt;
        int num=(double)100*comp/n+0.5;
        a[1-top]=num;
        for(int i=1; i<=cnt && now<=n; i++){
            p.push(top-t[now]);
            st[now]=1-top; now++;
        }
        if(p.empty()) end=0-top;
    }
    for(int i=1; i<=end; i++){
        while(a[i]==0 && i<=end) {
            a[i] = a[i - 1];
            i++;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=t[i]; j++){
            if(a[st[i]+j-1]==j){
                result++;
                break;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
/*  6 9 12 19 26 48 50 54 57 63 69 71 84 98
*/