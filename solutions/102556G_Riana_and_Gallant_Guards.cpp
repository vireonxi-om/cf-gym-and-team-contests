// Problem: Riana and Gallant Guards
// URL: https://codeforces.com/gym/102556/problem/G
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, x, y;

int main(){
    scanf("%d%d%d%d", &n, &m, &x, &y);
    int a=min(x, n-x+1), b=min(y, m-y+1);
    int tot=m*n, ans=a*b;
    if(tot-ans<=ans) printf("I don't wanna do this anymore!\n");
    else printf("%d\n", ans);
    return 0;
}

