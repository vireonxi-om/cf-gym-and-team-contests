// Problem: Grammy and Ropes
// URL: https://codeforces.com/gym/103055/problem/I
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10];
string s;

int main(){
    for(int i=1; i<=6; i++){
        cin>>s;
        if(s[0]=='t') a[i]=1;
        else a[i]=0;
    }
    int cnt=3;
    if(a[1]==a[4]) cnt--;
    if(a[2]==a[5]) cnt--;
    if(a[3]==a[6]) cnt--;
    if(a[1]+a[6]+a[3]+a[4]==0 && a[2]+a[5]==2) printf("7\n");
    else if(a[1]+a[6]+a[3]+a[4]==4 && a[2]+a[5]==0) printf("7\n");
    else{
        if(cnt==0) printf("8\n");
        if(cnt==1) printf("6\n");
        if(cnt==2) printf("5\n");
        if(cnt==3) printf("4\n");
    }
    return 0;
}