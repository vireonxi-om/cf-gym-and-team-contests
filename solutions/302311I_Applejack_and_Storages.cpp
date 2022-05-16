// Problem: Applejack and Storages
// URL: https://codeforces.com/gym/302311/problem/I
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, a[110000], k, num, m[3];
char opt;
set <pair<int, int>> len;

int main() {
    scanf("%d", &n);
    int l;
    for(int i=1; i<=n; i++){
        scanf("%d", &l);
        a[l]++;
    }
    for(int i=1; i<110000; i++) {
        if(a[i]!=0) len.emplace(a[i],i);
    }
    scanf("%d", &k);
    for(int i=1; i<=k; i++){
        getchar(); scanf("%c", &opt);
        scanf("%d", &num);

        len.erase(make_pair(a[num], num));
        if(opt=='+') a[num]++;
        else a[num]--;
        len.emplace(a[num], num);

        int j=0;
        memset(m,0,sizeof(m));
        for (auto it=len.rbegin(); it!=len.rend() && j<=2; it++){
            m[j]=it->first; j++;
        }
        if(m[0]>=8) printf("YES\n");
        else if(m[0]>=6 && m[1]>=2) printf("YES\n");
        else if(m[0]>=4 && m[1]>=4) printf("YES\n");
        else if(m[0]>=4 && m[1]>=2 && m[2]>=2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
