// Problem: Plasticine zebra
// URL: https://codeforces.com/gym/314707/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
char s[110000];

int main(){
    scanf("%s", &s);
    int len=strlen(s);
    int a=0, b=len-1, ans=0;
    while(a+1<len && s[a+1]!=s[a]) a++;
    while(b>0 && s[b-1]!=s[b]) b--;
    if(b<=a) ans=len;
    else{
        if(s[len-1]!=s[0]) ans=len-b+a+1;
        else ans=max(a+1, len-b);
        int pos=a+1;
        while(pos+1<b){
            if(s[pos+1]!=s[pos]){
                int l=1;
                while(s[pos+1]!=s[pos]){
                    pos++; l++;
                }
                ans=max(ans, l);
            }
            else{
                while(s[pos+1]==s[pos]) pos++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}