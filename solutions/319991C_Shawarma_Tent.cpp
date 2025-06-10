// Problem: Shawarma Tent
// URL: https://codeforces.com/gym/319991/problem/C
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, sx, sy, cu, cd, cl, cr;

int main(){
    int mu=2e9, md=-1, mr=2e9, ml=-1;
    scanf("%d%d%d", &n, &sx, &sy);
    int a, b;
    for(int i=1; i<=n; i++){
        scanf("%d%d", &a, &b);
        if(a>sx){ cr++; mr=min(mr, a);}
        else if(a<sx){ cl++; ml=max(ml, a);}
        if(b>sy){ cu++; mu=min(mu, b);}
        else if(b<sy){ cd++; md=max(md, b);}
    }
    int m=max(cl, max(cr, max(cu, cd)));
    if(cl==m){ printf("%d\n", m); printf("%d %d\n", ml, sy);}
    else if(cr==m){ printf("%d\n", m); printf("%d %d\n", mr, sy);}
    else if(cu==m){ printf("%d\n", m); printf("%d %d\n", sx, mu);}
    else{ printf("%d\n", m); printf("%d %d\n", sx, md);}
    return 0;
}