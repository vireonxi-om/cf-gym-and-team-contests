// Problem: The Same Calendar
// URL: https://codeforces.com/gym/329293/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans;

bool leap(int x){
    if(x%400==0) return true;
    if(x%100==0) return false;
    if(x%4==0) return true;
    return false;
}

bool yes(int x, int y){
    if(leap(x) && leap(y)) return true;
    if(leap(x) || leap(y)) return false;
    return true;
}

int main(){
    scanf("%d", &n);
    ans=n+1;
    int cnt=1;
    if(leap(n)) cnt++;
    while(1){
        cnt++;
        if(leap(ans)) cnt++;
        ans++;
        if(cnt%7==0){
            if(yes(n, ans)) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}