// Problem: Perfect Keyboard
// URL: https://codeforces.com/gym/308347/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[210], ad[30], used[30], cnt[30];
char s[210];
vector<int> ans;
vector<int> g[30];

void fil(int i){
    ans.push_back(i);
    used[i]=1;
    for(auto x:g[i]){
        if(used[x]==0) fil(x);
    }
}

void solve(){
    scanf("%s", &s);
    n=strlen(s);
    bool can=true;
    for(int i=0; i<n; i++) a[i]=s[i]-'a';
    for(int i=0; i<26; i++) {
        ad[i]=0; used[i]=0;
        g[i].clear();
    }
    for(int i=0; i<n-1; i++){
        g[a[i]].push_back(a[i+1]);
        g[a[i+1]].push_back(a[i]);
    }
    int cnt1=0;
    for(int i=0; i<26; i++){
        for(int k=0; k<26; k++) cnt[k]=0;
        for(auto x:g[i]) cnt[x]=1;
        int sum=0;
        for(int k=0; k<26; k++) sum+=cnt[k];
        ad[i]=sum;
        if(sum>2) can=false;
        if(sum==1) cnt1++;
    }
    if(cnt1%2==1 || cnt1==0 && n>1) can=false;
    ans.clear();
    if(can==false) printf("NO\n");
    else{
        printf("YES\n");
        for(int i=0; i<26; i++)
            if(used[i]==0 && ad[i]==1) fil(i);
        for(int i=0; i<26; i++){
            if(used[i]==0) ans.push_back(i);
        }
        for(auto x:ans) printf("%c", x+'a');
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

