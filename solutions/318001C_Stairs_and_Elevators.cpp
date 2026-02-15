// Problem: Stairs and Elevators
// URL: https://codeforces.com/gym/318001/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, c1, c2, v, q;
set<int> s, e;

int main(){
    scanf("%d%d%d%d%d", &n, &m, &c1, &c2, &v);
    int num;
    for(int i=1; i<=c1; i++){
        scanf("%d", &num);
        s.insert(num);
    }
    for(int i=1; i<=c2; i++){
        scanf("%d", &num);
        e.insert(num);
    }
    scanf("%d", &q);
    while(q--){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        if(x1>x2) swap(x1, x2);
        int h=abs(y1-y2);
        int ts=0, te=0;
        auto s1=s.lower_bound(x1), e1=e.lower_bound(x1);
        int t1, t2;
        if(s1!=s.end()){
            if((*s1)>x2){
                t1=2*(*s1)-x2-x1;
            }
            else t1=x2-x1;
            ts=h+t1;
        }
        if(s1!=s.begin()){
            s1--;
            t2=(x1+x2)-2*(*s1);
            if(ts) ts=min(ts, h+t2);
            else ts=h+t2;
        }
        if(e1!=e.end()){
            if((*e1)>x2){
                t1=2*(*e1)-x2-x1;
            }
            else t1=x2-x1;
            te=(h+v-1)/v+t1;
        }
        if(e1!=e.begin()){
            e1--;
            t2=(x1+x2)-2*(*e1);
            if(te) te=min(te, (h+v-1)/v+t2);
            else te=(h+v-1)/v+t2;
        }
        int ans;
        if(ts==0) ans=te;
        else if(te==0) ans=ts;
        else ans=min(ts, te);
        if(h==0) ans=x2-x1;
        printf("%d\n", ans);
    }
    return 0;
}



