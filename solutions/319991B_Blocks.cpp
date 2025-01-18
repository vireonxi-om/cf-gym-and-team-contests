// Problem: Blocks
// URL: https://codeforces.com/gym/319991/problem/B
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
char s[210];
vector<int> ans;

int main(){
    scanf("%d%s", &n, &s);
    int cnt0=0, cnt1=0;
    for(int i=0; i<n; i++){
        if(s[i]=='B') cnt1++;
        else cnt0++;
    }
    if(cnt1%2==0){
        for(int i=0; i<n; i++){
            if(s[i]=='B' && s[i+1]!=s[i]){
                ans.push_back(i+1);
                s[i+1]='B';
            }
            else if(s[i]=='B' && s[i+1]==s[i]){
                ans.push_back(i+1);
                i++;
            }
        }
        printf("%d\n", ans.size());
        for(auto x:ans) printf("%d ", x); printf("\n");
    }
    else if(cnt0%2==0){
        for(int i=0; i<n; i++){
            if(s[i]=='W' && s[i+1]!=s[i]){
                ans.push_back(i+1);
                s[i+1]='W';
            }
            else if(s[i]=='W' && s[i+1]==s[i]){
                ans.push_back(i+1);
                i++;
            }
        }
        printf("%d\n", ans.size());
        for(auto x:ans) printf("%d ", x); printf("\n");
    }
    else printf("-1\n");
    return 0;
}