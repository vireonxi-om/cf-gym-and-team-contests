// Problem: Character Swap (Hard Version)
// URL: https://codeforces.com/gym/309006/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cnta[30], cntb[30];
char a[60], b[60];

void solve(){
    for(int i=0; i<=26; i++){cnta[i]=0; cntb[i]=0;}
    scanf("%d", &n);
    scanf("%s%s", &a, &b);
    for(int i=0; i<n; i++){
        cnta[a[i]-'a']++;
        cntb[b[i]-'a']++;
    }
    bool can=true;
    for(int i=0; i<26; i++) if((cnta[i]+cntb[i])%2!=0) can=false;
    if(!can){ printf("No\n"); return;}
    vector<pair<int, int>> ans; int cnt=0;
    for(int i=0; i<n; i++){
        int x=a[i]-'a', y=b[i]-'a';
        if(x!=y){
            for(int j=i+1; j<n; j++){
                if(a[j]-'a'==x){
                    ans.push_back(make_pair(j+1, i+1));
                    swap(a[j], b[i]);
                    cnt++;
                    break;
                }
                else if(b[j]-'a'==x){
                    ans.push_back(make_pair(j+1, j+1));
                    ans.push_back(make_pair(j+1, i+1));
                    swap(a[j], b[j]);
                    swap(a[j], b[i]);
                    cnt+=2;
                    break;
                }
            }
        }
    }
    printf("Yes\n%d\n", cnt);
    for(auto[x, y] : ans) printf("%d %d\n", x, y);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
