// Problem: Pluses and Minuses
// URL: https://codeforces.com/gym/302720/problem/J
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
char a[1100000];
long long n, result;

void solve(){
    scanf("%s", &a);
    n=strlen(a);
    result=(long long)n;
    int sum=0;
    for(int i=0; i<n; i++){
        if(a[i]=='+') sum++;
        else sum--;
        if(sum<0){
            result=result+i+1;
            sum=0;
        }
    }
    printf("%lld\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}

