// Problem: Memory and De-Evolution
// URL: https://codeforces.com/gym/328644/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, y;

int main(){
    scanf("%d%d", &x, &y);
    int m1=y, m2=y, m3=y, cnt=0;
    while(1){
        m1=m2;
        int t=m3;
        m3=m3+m2-1;
        m2=t;
        cnt++;
        if(m3>=x){ cnt+=2; break;}
    }
    printf("%d\n", cnt);
    return 0;
}
