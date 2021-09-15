// Problem: The Artful Expedient
// URL: https://codeforces.com/gym/319427/problem/A
// Rating: 1100
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
set<int> x, y;


int main(){
    scanf("%d", &n);
    int num;
    for(int i=1; i<=n; i++){ scanf("%d", &num); x.insert(num);}
    for(int i=1; i<=n; i++){ scanf("%d", &num); y.insert(num);}
    int cnt=0;
    for(auto t:x){
        for(auto s:y){
            int now=s^t;
            if(x.find(now)!=x.end() || y.find(now)!=y.end()) cnt++;
        }
    }
    if(cnt%2==0) printf("Karen\n");
    else printf("Koyomi\n");
    return 0;
}
