// Problem: Distinct Characters Queries
// URL: https://codeforces.com/gym/309196/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
char s[110000];
set<int> pos[30];

int main(){
    scanf("%s%d", s+1, &q);
    n=strlen(s+1);
    for(int i=1; i<=n; i++) pos[s[i]-'a'].insert(i);
    while(q--){
        int num;
        scanf("%d", &num);
        if(num==1){
            int x; char y;
            scanf("%d %c", &x, &y);
            pos[s[x]-'a'].erase(x);
            s[x]=y;
            pos[y-'a'].insert(x);
        }
        else{
            int l, r;
            scanf("%d%d", &l, &r);
            int cnt=0;
            set<int>::iterator it;
            for(int i=0; i<26; i++){
                it=pos[i].lower_bound(l);
                if(it!=pos[i].end() && (*it)<=r) cnt++;
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}