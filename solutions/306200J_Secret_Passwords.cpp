// Problem: Secret Passwords
// URL: https://codeforces.com/gym/306200/problem/J
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, used[26];
char s[1100000];
vector<int> a[26];

void dfs(int k){
    used[k]=1;
    for(auto x:a[k]){
        if(used[x]!=1) dfs(x);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%s", &s);
        int l=strlen(s);
        for(int j=1; j<l; j++){
            a[s[j]-'a'].push_back(s[j-1]-'a');
            a[s[j-1]-'a'].push_back(s[j]-'a');
        }
        a[s[0]-'a'].push_back(s[0]-'a');
    }
    int result=0;
    for(int i=0; i<26; i++){
        if(a[i].empty()==0 && used[i]==0){
            dfs(i);
            result++;
        }
    }
    printf("%d\n", result);
    return 0;
}
