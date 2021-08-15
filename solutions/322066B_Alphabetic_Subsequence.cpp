// Problem: Alphabetic Subsequence
// URL: https://codeforces.com/gym/322066/problem/B
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int tot=0, num[15];
char s[110];
set<pair<int, int>> ans[15];


int main(){
    scanf("%s", s+1);
    int len=strlen(s+1);
    for(int i=0; i<=9; i++){
        ans[i].insert(make_pair(0, 1));
        num[i]=1<<i;
    }
    for(int i=1; i<=len; i++){
        int now=s[i]-'0';
        for(auto x:ans[now]){
            int nxt=(x.first|num[now]);
            if(nxt==1023){ tot+=x.second; continue;}
            for(int t=0; t<=9; t++){
                if(t==now) continue;
                int m=nxt|num[t];
                if(m==nxt) continue;
                auto it=ans[t].lower_bound(make_pair(m, 0));
                if(it==ans[t].end() || (*it).first>m) ans[t].insert(make_pair(m, x.second));
                else{
                    int cnt=x.second+(*it).second;
                    ans[t].erase(it);
                    ans[t].insert(make_pair(m, cnt));
                }
            }
        }
        ans[now].clear();
    }
    printf("%d\n", tot);
}
