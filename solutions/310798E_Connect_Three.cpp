// Problem: Connect Three
// URL: https://codeforces.com/gym/310798/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
set<pair<int, int>> xy, ans;
int used[1100][1100];

int main(){
    int x, y;
    for(int i=1; i<=3; i++){
        scanf("%d%d", &x, &y);
        xy.insert(make_pair(x,y));
        ans.insert(make_pair(x,y));
        used[x][y]=1;
    }
    auto it1=xy.begin(), it2=xy.end();
    it1++; int mid=(*it1).first;
    it1--; it2--;
    for(int i=(*it1).first; i<=mid; i++){
        if(used[i][(*it1).second]) continue;
        else{
            used[i][(*it1).second]=1;
            ans.insert(make_pair(i, (*it1).second));
        }
    }
    for(int i=(*it2).first; i>=mid; i--){
        if(used[i][(*it2).second]) continue;
        else{
            used[i][(*it2).second]=1;
            ans.insert(make_pair(i, (*it2).second));
        }
    }
    int ymin=1100, ymax=-1;
    for(auto it=xy.begin(); it!=xy.end(); it++){
        ymin=min(ymin, (*it).second);
        ymax=max(ymax, (*it).second);
    }
    for(int j=ymin; j<=ymax; j++){
        if(used[mid][j]) continue;
        else{
            used[mid][j]=1;
            ans.insert(make_pair(mid, j));
        }
    }
    printf("%d\n", ans.size());
    for(auto x:ans){
        printf("%d %d\n", x.first, x.second);
    }
    return 0;
}
