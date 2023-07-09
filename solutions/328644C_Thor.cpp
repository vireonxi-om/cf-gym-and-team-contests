// Problem: Thor
// URL: https://codeforces.com/gym/328644/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
set<int> s, a[310000];


int main(){
    scanf("%d%d", &n, &q);
    int t, num, now=1;
    while(q--){
        scanf("%d%d", &t, &num);
        if(t==1){
            a[num].insert(now);
            s.insert(now++);
        }
        else if(t==2){
            for(auto x:a[num]) s.erase(x);
            a[num].clear();
        }
        else{
            while(!s.empty() && (*s.begin())<=num) s.erase(s.begin());
        }
        printf("%d\n", s.size());
    }
    return 0;
}

