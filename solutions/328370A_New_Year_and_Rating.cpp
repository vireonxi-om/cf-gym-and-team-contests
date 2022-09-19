// Problem: New Year and Rating
// URL: https://codeforces.com/gym/328370/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    scanf("%d", &n);
    int c, d, sum=0;
    int pmin=-2e9, pmax=2e9;
    bool can=true;
    for(int i=1; i<=n; i++){
        scanf("%d%d", &c, &d);
        if(d==1) pmin=max(pmin, 1900-sum);
        else pmax=min(pmax, 1899-sum);
        sum+=c;
        if(pmin>pmax) can=false;
    }
    if(can){
        if(pmax>1e9) printf("Infinity\n");
        else printf("%d\n", pmax+sum);
    }
    else printf("Impossible\n");
    return 0;
}
