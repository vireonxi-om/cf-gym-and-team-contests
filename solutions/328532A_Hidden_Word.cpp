// Problem: Hidden Word
// URL: https://codeforces.com/gym/328532/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[30], ans[2][20];


int main(){
    scanf("%s", a+1);
    int c, pos1, pos2;
    for(c=0; c<26; c++){
        int cnt=0;
        pos1=0, pos2=0;
        for(int j=1; j<=27; j++){
            if(a[j]=='A'+c){
                cnt++;
                if(pos1) pos2=j;
                else pos1=j;
            }
        }
        if(cnt>1) break;
    }
    if(pos2==pos1+1){
        printf("Impossible\n");
        return 0;
    }
    int l1=pos1-1, l2=27-pos2, l3=pos2-pos1-1;
    int p=(l1+l2)/2+1;
    int i, p1=1, p2=pos2;
    for(i=p-1; i>=1; i--){
        pos2++;
        if(pos2>27) break;
        ans[0][i]=a[pos2];
    }
    if(pos2>27){
        for(; i>=1; i--){
            if(p1==pos1) break;
            ans[0][i]=a[p1];
            p1++;
        }
        i=1;
    }
    else{
        for(i=1; ; i++){
            pos2++;
            if(pos2>27) break;
            ans[1][i]=a[pos2];
        }
    }
    for(;;i++){
        if(p1==pos1) break;
        ans[1][i]=a[p1];
        p1++;
    }
    for(int j=p; j<=13; j++){
        if(p1>=p2) break;
        ans[0][j]=a[p1];
        p1++;
    }
    for(int j=13; ;j--){
        if(p1>=p2) break;
        ans[1][j]=a[p1];
        p1++;
    }
    printf("%s\n%s\n", ans[0]+1, ans[1]+1);
    return 0;
}