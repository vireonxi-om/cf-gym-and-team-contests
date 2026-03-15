// Problem: Remove Adjacent
// URL: https://codeforces.com/gym/308347/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char a[110];

int main(){
    vector<int> ch[30];
    scanf("%d%s", &n, &a);
    for(int i=0; i<n; i++){
        ch[a[i]-'a'].push_back(i);
    }
    int result=0;
    for(int i=25; i>0; i--){
        for(auto x:ch[i]){
            bool can=false;
            int j=x-1;
            while(j>=0 && ((a[j]-'a')==i || a[j]=='0')) j--;
            if(j>=0 && a[j]==('a'+i-1)) can=true;
            j=x+1;
            while(j<n && ((a[j]-'a')==i || a[j]=='0')) j++;
            if(j<n && a[j]==('a'+i-1)) can=true;
            if(can){
                a[x]='0';
                result++;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}


