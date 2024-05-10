// Problem: Buses Between Cities
// URL: https://codeforces.com/gym/329293/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, ta, b, tb, h, m;


int main(){
    scanf("%d%d%d%d%d%c%d", &a, &ta, &b, &tb, &h, &m, &m);
    int l=h*60+m-tb, r=h*60+m+ta;
    int cnt=0;
    for(int i=300; i<=1439; i+=b){
        if(i>l && i<r) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}