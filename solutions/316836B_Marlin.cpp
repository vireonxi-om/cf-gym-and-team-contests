// Problem: Marlin
// URL: https://codeforces.com/gym/316836/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k;
char a[4][110];

int main(){
    scanf("%d%d", &n, &k);
    if(k%2==0){
        for(int i=1; i<=k/2; i++){
            a[1][i]='#';
            a[2][i]='#';
        }
    }
    else if(k%2==1){
        if(k==1) a[1][n/2]='#';
        else if(k==3) {
            a[1][n/2]='#';
            a[1][1]='#';
            a[1][n-2]='#';
        }
        else{
            for(int i=1; i<=k/2+1; i++){
                a[1][i]='#'; a[2][i]='#';
            }
            a[1][2]='.';
        }
    }
    printf("YES\n");
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]=='#') printf("#");
            else printf(".");
        }
        printf("\n");
    }
}
