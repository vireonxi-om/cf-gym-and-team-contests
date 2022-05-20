// Problem: s-palindrome
// URL: https://codeforces.com/gym/328644/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[1100];
set<char> a;


int main(){
    scanf("%s", s+1);
    n=strlen(s+1);
    a.insert('A'); a.insert('H'); a.insert('I'); a.insert('M');
    a.insert('O'); a.insert('o'); a.insert('T'); a.insert('U');
    a.insert('V'); a.insert('v'); a.insert('W'); a.insert('w');
    a.insert('X'); a.insert('x'); a.insert('Y');
    bool can=true;
    if(n%2 && a.find(s[n/2+1])==a.end()) can=false;
    for(int i=1; i<=n/2; i++){
        if(s[i]==s[n-i+1]){
            if(a.find(s[i])!=a.end()) continue;
        }
        else{
            if(s[i]=='b' && s[n-i+1]=='d' || s[i]=='d' && s[n-i+1]=='b') continue;
            if(s[i]=='p' && s[n-i+1]=='q' || s[i]=='q' && s[n-i+1]=='p') continue;
        }
        can=false;
    }
    if(can) printf("TAK\n");
    else printf("NIE\n");
    return 0;
}

