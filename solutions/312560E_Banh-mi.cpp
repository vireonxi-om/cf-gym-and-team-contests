// Problem: Banh-mi
// URL: https://codeforces.com/gym/312560/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, q, mod[110000], pre1[110000];
char s[110000];

int main(){
    scanf("%d%d", &n, &q);
    scanf("%s", s+1);
    int ls=strlen(s+1);
    mod[0]=1;
    for(int i=1; i<=ls; i++){
        pre1[i]=pre1[i-1];
        if(s[i]=='1') pre1[i]++;
        mod[i]=(mod[i-1]*2)%1000000007;
    }
    for(int i=1; i<=q; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        int num=r-l+1, num1=pre1[r]-pre1[l-1];
        int result=(mod[num]-mod[num-num1]+1000000007)%1000000007;
        printf("%d\n", result);
    }
    return 0;
}