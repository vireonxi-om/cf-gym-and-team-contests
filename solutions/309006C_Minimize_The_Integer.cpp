// Problem: Minimize The Integer
// URL: https://codeforces.com/gym/309006/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[310000];

void solve(){
    vector<char> a, b, ans;
    vector<char>::iterator ita, itb;
    scanf("%s", s+1);
    int l=strlen(s+1);
    for(int i=1; i<=l; i++){
        if((s[i]-'0')%2==0) a.push_back(s[i]);
        else b.push_back(s[i]);
    }
    ita=a.begin(); itb=b.begin();
    while(ita!=a.end() && itb!=b.end()){
        if((*ita)<(*itb)){ ans.push_back((*ita)); ita++;}
        else{ ans.push_back((*itb)); itb++;}
    }
    while(ita!=a.end()){
        ans.push_back((*ita));
        ita++;
    }
    while(itb!=b.end()){
        ans.push_back((*itb));
        itb++;
    }
    for(auto x:ans) printf("%c", x);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
