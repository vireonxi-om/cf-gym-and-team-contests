// Problem: Obtain The String
// URL: https://codeforces.com/gym/308347/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[110000][30], sl, tl, result;
char s[110000], t[110000];

void solve(){
    vector<int> a[30];
    scanf("%s%s", &s, &t);
    sl=strlen(s); tl=strlen(t);
    for(int i=0; i<sl; i++) for(int j=0; j<26; j++) cnt[i][j]=0;
    for(int i=0; i<sl; i++){
        cnt[i][s[i]-'a']++;
        a[s[i]-'a'].push_back(i);
        if(i>0) for(int j=0; j<26; j++) cnt[i][j]+=cnt[i-1][j];
    }
    result=0;
    int now=0;
    vector<int>::iterator it=a[t[now]-'a'].begin();
    bool next=false, can=true;
    while(now<tl){
        char ch=t[now];
        if(it==a[ch-'a'].end()) {can=false; break;}
        while(t[now]==ch){
            now++; it++;
            if(now==tl) break;
            if(it==a[ch-'a'].end() && t[now]==ch){
                next=true; break;
            }
        }
        if(now==tl) {result++; break;}
        it=a[t[now]-'a'].begin()+cnt[*(--it)][t[now]-'a'];
        if(it==a[t[now]-'a'].end()) next=true;
        if(next==false) continue;
        else{
            result++;
            it=a[t[now]-'a'].begin();
            next=false;
        }
    }
    if(can==false) printf("-1\n");
    else printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

