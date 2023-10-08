// Problem: Equality
// URL: https://codeforces.com/gym/101291/problem/F
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c;

int main(){
    char ch;
    for(int i=1; i<=9; i++){
        scanf("%c", &ch);
        if(i==1) a=ch-'0';
        else if(i==5) b=ch-'0';
        else if(i==9) c=ch-'0';
    }
    if(a+b==c) printf("YES\n");
    else printf("NO\n");
    return 0;
}
