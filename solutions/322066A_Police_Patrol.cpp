// Problem: Police Patrol
// URL: https://codeforces.com/gym/322066/problem/A
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k, ans;

int main(){
    scanf("%d%d", &n, &k);
    int t=n/(k+1);
    ans=t*2;
    int lft=n-t*(k+1);
    if(lft>1) ans+=2;
    else if(lft==1) ans++;
    printf("%d\n", ans);
}
