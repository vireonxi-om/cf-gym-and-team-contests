// Problem: Alice, Bob and Candies
// URL: https://codeforces.com/gym/303728/problem/G
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, s[1100], a, b, m;

void solve(){
    scanf("%d", &n);
    a=0; b=0; m=1;
    for(int i=1; i<=n; i++) scanf("%d", &s[i]);
    int an=0, bn=0, ax=1, bx=n;
    while(ax<=bx){
        if(m%2==1){
            while(1){
                an+=s[ax]; a+=s[ax];
                ax++;
                if(an>bn || ax>bx){
                    m++; bn=0; break;
                }
            }
        }
        else{
            while(1){
                bn+=s[bx]; b+=s[bx];
                bx--;
                if(bn>an || bx<ax){
                    m++; an=0; break;
                }
            }
        }
    }
    m--;
    printf("%d %d %d\n", m, a, b);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
