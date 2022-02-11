// Problem: Playlist
// URL: https://codeforces.com/gym/310796/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll sum, result;

struct cmp{
    bool operator() (int a,int b){
        return a>b;
    }
};
multiset<int,cmp> s;
multiset<pair<int, int>> b;

int main(){
    scanf("%d%d", &n, &k);
    int x, y;
    for(int i=1; i<=n; i++){
        scanf("%d%d", &x, &y);
        b.insert(make_pair(y, x));
    }
    auto itb=b.end(); itb--;
    bool end=false;
    while(!end){
        int now=(*itb).first;
        while((*itb).first==now){
            s.insert((*itb).second);
            auto it=s.end(); it--;
            if(s.size()>k){ sum=sum+(*itb).second-(*it); s.erase(it);}
            else sum+=(*itb).second;
            if(itb==b.begin()){ end=true; break;}
            itb--;
        }
        result=max(result, now*sum);
    }
    printf("%lld\n", result);
}

