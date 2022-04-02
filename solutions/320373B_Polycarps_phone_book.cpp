// Problem: Polycarp's phone book
// URL: https://codeforces.com/gym/320373/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
char s[71000][20], a[710000][20];
vector<pair<int, ll>> p[710000];
set<pair<int, ll>> f, ans;

void func(int len, int t){
    ll now;
    for(int i=0; i<=9-len; i++){
        now=0;
        for(int j=i; j<=i+len-1; j++){
            now*=10;
            now+=s[t][j]-'0';
        }
        p[t].push_back(make_pair(len, now));
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%s", &s[i]);
        for(int j=1; j<=9; j++) func(j, i);
        sort(p[i].begin(), p[i].end());
        auto it2=p[i].begin();
        auto it=it2; it2++;
        while(it!=p[i].end()){
            while(it2!=p[i].end() && (*it2)==(*it)) {it++; it2++;}
            if(f.find((*it))!=f.end()){ if(ans.find((*it))!=ans.end()) ans.erase(ans.find((*it)));}
            else {f.insert((*it)); ans.insert((*it));}
            it++; it2++;
        }
    }
    for(int i=1; i<=n; i++){
        for(auto x:p[i]){
            if(ans.find(x)!=ans.end()){
                ll num=x.second; int l=x.first;
                while(l){
                    a[i][l]='0'+num%10;
                    num/=10; l--;
                }
                a[i][x.first+1]='\0';
                break;
            }
        }
    }
    for(int i=1; i<=n; i++){
        printf("%s\n", a[i]+1);
    }
}

