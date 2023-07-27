// Problem: Vova and Trophies
// URL: https://codeforces.com/gym/312560/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)

#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
char s[110000];
vector<pair<int, int>> g;

int main(){
    scanf("%d%s", &n, &s);
    for(int i=0; i<n; i++){
        if(i==0 && s[i]=='G'){
            int a=i; while(i<n-1 && s[i+1]=='G') i++;
            int b=i; g.push_back(make_pair(a, b));
        }
        else if(i>0 && s[i]=='G' && s[i-1]=='S'){
            int a=i; while(i<n-1 && s[i+1]=='G') i++;
            int b=i; g.push_back(make_pair(a, b));
        }
    }
    int result=0;
    if(g.size()==1) result=(*g.begin()).second-(*g.begin()).first+1;
    else if(g.size()==2){
        auto it1=g.begin(), it2=++g.begin();
        int len1=(*it1).second-(*it1).first+1, len2=(*it2).second-(*it2).first+1;
        if((*it1).second+2==(*it2).first) result=len1+len2;
        else result=max(len1, len2)+1;
    }
    else if(g.size()>=3){
        int tot=g.size();
        for(int i=0; i<tot-1; i++){
            int len1=g[i].second-g[i].first+1, len2=g[i+1].second-g[i+1].first+1;
            if(g[i].second+2==g[i+1].first) result=max(result, len1+len2+1);
            else result=max(result, max(len1+1, len2+1));
        }
    }
    printf("%d\n", result);
}
