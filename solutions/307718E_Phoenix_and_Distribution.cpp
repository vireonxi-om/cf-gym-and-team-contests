// Problem: Phoenix and Distribution
// URL: https://codeforces.com/gym/307718/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k, a[30];
char s[110000];

void solve(){
    for(int i=0; i<=26; i++) a[i]=0;
    scanf("%d%d%s", &n, &k, &s);
    for(int i=0; i<n; i++) a[s[i]-'a']++;
    sort(s, s+n);
    vector<char> ans;
    int cnt=a[s[n-1]-'a'], fir=n-a[s[n-1]-'a'];
    if(k==1){
        for(int i=0; i<n; i++) ans.push_back(s[i]);
    }
    else if(fir==0){
        for(int i=1; i<=(n+k-1)/k; i++) ans.push_back(s[n-1]);
    }
    else if(fir<k) ans.push_back(s[n-1]);
    else if(fir==k && s[0]==s[k-1]){
        ans.push_back(s[0]);
        for(int i=1; i<=(cnt+k-1)/k; i++) ans.push_back(s[n-1]);
    }
    else if(s[0]==s[k-1]){
        ans.push_back(s[0]);
        for(int i=k; i<n; i++) ans.push_back(s[i]);
    }
    else ans.push_back(s[k-1]);
    for(auto x:ans) printf("%c", x); printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

