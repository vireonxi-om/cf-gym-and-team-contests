// Problem: Permutation Game
// URL: https://codeforces.com/gym/323731/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, l[110], a[110];
set<int> t;


int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &l[i]);
    }
    for(int i=1; i<=n; i++) t.insert(i);
    bool can=true;
    for(int i=2; i<=m; i++){
        int num=(l[i]-l[i-1]+n)%n; if(num==0) num+=n;
        if(a[l[i-1]] && a[l[i-1]]!=num || t.find(num)==t.end() && a[l[i-1]]==0){ can=false; break;}
        t.erase(num);
        a[l[i-1]]=num;
    }
    if(!can) printf("-1\n");
    else {
        for(int i=1; i<=n; i++){
            if(a[i]) continue;
            else{
                a[i]=(*t.begin());
                t.erase(t.begin());
            }
        }
        for(int i=1; i<=n; i++) printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}
