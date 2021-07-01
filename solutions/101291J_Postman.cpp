// Problem: Postman
// URL: https://codeforces.com/gym/101291/problem/J
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
priority_queue<pair<int, int>> q1, q2;
 
int main(){
    scanf("%d%d", &n, &k);
    int x, num;
    for(int i=1; i<=n; i++){
        scanf("%d%d", &x, &num);
        if(x>0) q1.push(make_pair(x, num));
        else if(x<0) q2.push(make_pair(-x, num));
    }
    ll d=0;
    while(!q1.empty()){
        d+=(q1.top().second+k-1) / k * (ll) q1.top().first;
        int now=(q1.top().second+k-1) / k * k - q1.top().second;
        q1.pop();
        while(now && !q1.empty()){
            x=q1.top().first;
            num=q1.top().second;
            q1.pop();
            if(now<num){
                num-=now; now=0; 
                q1.push(make_pair(x, num));
            }
            else now-=num;
        }
    }
    while(!q2.empty()){
        d+=(q2.top().second+k-1) / k * (ll) q2.top().first;
        int now=(q2.top().second+k-1) / k * k - q2.top().second;
        q2.pop();
        while(now && !q2.empty()){
            x=q2.top().first;
            num=q2.top().second;
            q2.pop();
            if(now<num){
                num-=now; now=0; 
                q2.push(make_pair(x, num));
            }
            else now-=num;
        }
    }
    d*=2;
    printf("%lld\n", d);
    return 0;
}