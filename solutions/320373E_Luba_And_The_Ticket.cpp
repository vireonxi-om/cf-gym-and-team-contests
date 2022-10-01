// Problem: Luba And The Ticket
// URL: https://codeforces.com/gym/320373/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int a[10];
priority_queue<int> ans;

int main(){
    for(int i=1; i<=6; i++) scanf("%1d", &a[i]);
    if(a[1]+a[2]+a[3]>a[4]+a[5]+a[6]){
        for(int i=1; i<=3; i++){
            ans.push(a[i]);
        }
        for(int i=4; i<=6; i++){
            ans.push(9-a[i]);
        }
    }
    else if(a[1]+a[2]+a[3]<=a[4]+a[5]+a[6]){
        for(int i=4; i<=6; i++){
            ans.push(a[i]);
        }
        for(int i=1; i<=3; i++){
            ans.push(9-a[i]);
        }
    }
    int d=abs(a[1]+a[2]+a[3]-(a[4]+a[5]+a[6]));
    int cnt=0;
    while(d>0){
        int num=ans.top();
        ans.pop();
        d-=num;
         cnt++;
    }
    printf("%d\n", cnt);
}

