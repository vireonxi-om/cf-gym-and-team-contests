// Problem: Kostya the Sculptor
// URL: https://codeforces.com/gym/328479/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans=0, id1, id2;
set<pair<pair<int, int>, pair<int, int>>> s;


int mini(int a, int b, int c){
    return min(min(a, b), c);
}


void build(int a, int b, int c, int i){
    if(a>b) swap(a, b);
    if(s.empty()){ s.insert(make_pair(make_pair(a, b), make_pair(c, i))); return;}
    auto it=s.lower_bound(make_pair(make_pair(a, b), make_pair(0, 0)));
    if((*it).first.first!=a || (*it).first.second!=b){
        s.insert(make_pair(make_pair(a, b), make_pair(c, i))); return;
    }
    int l=(*it).second.first, id=(*it).second.second;
    if(mini(a, b, c+l)>ans){ id1=i; id2=id; ans=mini(a, b, c+l);}
    if(c>l){ l=c; id=i; }
    s.erase(it);
    s.insert(make_pair(make_pair(a, b), make_pair(l, id)));
    return;
}

int main(){
    scanf("%d", &n);
    int a, b, c;
    for(int i=1; i<=n; i++){
        scanf("%d%d%d", &a, &b, &c);
        if(mini(a, b, c)>ans){ id1=i; id2=0; ans=mini(a, b, c);}
        build(a, b, c, i);
        build(a, c, b, i);
        build(b, c, a, i);
    }
    if(id2==0){
        printf("1\n%d\n", id1);
    }
    else printf("2\n%d %d\n", id1, id2);
    return 0;
}

