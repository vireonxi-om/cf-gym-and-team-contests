// Problem: Acacius and String
// URL: https://codeforces.com/gym/306616/problem/G
// Rating: 1500
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n;
char s[60];

void solve(){
    scanf("%d", &n);
    scanf("%s", &s);
    char a[]="abacaba";
    int cnt=0;
    for(int i=0; i<n-6; i++){
        if(s[i]==a[0]){
            bool yes=true;
            for(int j=1; j<=6; j++) if(s[i+j]!=a[j]) yes=false;
            if(yes) cnt++;
        }
    }
    bool can=false;
    if(cnt==1) can=true;
    if(cnt==0){
    for(int i=0; i<n-6; i++){
        if(s[i]==a[0] || s[i]=='?'){
            bool yes1=true;
            for(int j=1; j<=6; j++)
                if(s[i+j]!=a[j] && s[i+j]!='?') yes1=false;
            bool chk1=false, chk2=false, chk3=false, chk4=false;
            if(i<n-12) {for(int j=1; j<=6; j++)
                if(s[i+6+j]!=a[j]) chk1=true;}
            else chk1=true;
            if(i<n-10) {for(int j=3; j<=6; j++)
                if(s[i+4+j]!=a[j]) chk2=true;}
            else chk2=true;
            if(i>=6) {for(int j=0; j<=5; j++)
                if(s[i-6+j]!=a[j]) chk3=true;}
            else chk3=true;
            if(i>=4) {for(int j=0; j<=3; j++)
                if(s[i-4+j]!=a[j]) chk4=true;}
            else chk4=true;
            if(yes1 && chk1 && chk2 && chk3 && chk4){
                for(int j=0; j<=6; j++) s[i+j]=a[j];
                can=true;
                break;
            }
        }
    }
    }
    if(can){
        printf("YES\n");
        for(int i=0; i<n; i++){
            if(s[i]=='?') s[i]='z';
            printf("%c", s[i]);
        }
        printf("\n");
    }
    else printf("NO\n");

}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
