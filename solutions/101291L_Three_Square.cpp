// Problem: Three Square
// URL: https://codeforces.com/gym/101291/problem/L
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10], b[10];
set<pair<int, int>> s;

int main(){
    bool can=false;
    for(int i=1; i<=6; i++) scanf("%d", &a[i]);
    for(int i=1; i<=6; i+=2){
        if(a[i]>a[i+1]) swap(a[i], a[i+1]);
        s.insert(make_pair(a[i+1], a[i]));
    }
    if(a[2]==a[4] && a[4]==a[6]){
        if(a[1]+a[3]+a[5]==a[2]) can=true;
    }
    auto it=s.end();
    it--;
    int m=(*it).first-(*it).second, t5=(*it).first, t6=(*it).second;
    it--;
    int t1=(*it).first, t2=(*it).second;
    it--;
    int t3=(*it).first, t4=(*it).second;
    if((t1==m || t2==m) && (t3==m|| t4==m)){
        if(t1+t2+t3+t4+t6+t6==3*t5) can=true;
    }
    if(can) printf("YES\n");
    else printf("NO\n");
    return 0;
}
