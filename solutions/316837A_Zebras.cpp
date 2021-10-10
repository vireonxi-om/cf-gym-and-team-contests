// Problem: Zebras
// URL: https://codeforces.com/gym/316837/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
char s[210000];
vector<int> ans[210000];
set<int> zero, one;

int main(){
    scanf("%s", s+1);
    int n=strlen(s+1);
    for(int i=1; i<=n; i++){
        if(s[i]=='0') zero.insert(i);
        else one.insert(i);
    }
    int cnt=0;
    while(!zero.empty()){
        int now0=*zero.begin();
        ans[cnt].push_back(now0);
        zero.erase(now0);
        while(1){
            if(zero.empty() || one.empty()) break;
            auto it1=one.lower_bound(now0);
            if(it1==one.end()) break;
            auto it0=zero.lower_bound((*it1));
            if(it0==zero.end()) break;
            ans[cnt].push_back((*it1));
            ans[cnt].push_back((*it0));
            now0=*it0;
            zero.erase(it0);
            one.erase(it1);
        }
        cnt++;
    }
    if(!one.empty()){
        printf("-1\n");
        return 0;
    }
    else {
        printf("%d\n", cnt);
        for(int i=0; i<cnt; i++){
            printf("%d ", ans[i].size());
            for(auto x:ans[i]) printf("%d ", x);
            printf("\n");
        }
    }
    return 0;
}
