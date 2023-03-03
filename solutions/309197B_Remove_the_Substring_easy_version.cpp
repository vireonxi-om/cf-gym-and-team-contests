// Problem: Remove the Substring (easy version)
// URL: https://codeforces.com/gym/309197/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[210], t[210];
int ls, lt;

int main(){
    scanf("%s%s", s+1, t+1);
    ls=strlen(s+1); lt=strlen(t+1);
    int len=0;
    for(int i=0; i<=lt; i++){
        int l=1, r=ls;
        for(int j=1; j<=i; j++){
            while(s[l]!=t[j]) l++;
            l++;
        }
        for(int j=lt; j>i; j--){
            while(s[r]!=t[j]) r--;
            r--;
        }
        len=max(len, r-l+1);
    }
    printf("%d\n", len);
    return 0;
}
