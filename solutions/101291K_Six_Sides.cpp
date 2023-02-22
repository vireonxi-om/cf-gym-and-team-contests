// Problem: Six Sides
// URL: https://codeforces.com/gym/101291/problem/K
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10], b[10];

int main(){
    for(int i=1; i<=6; i++) scanf("%d", &a[i]);
    for(int i=1; i<=6; i++) scanf("%d", &b[i]);
    sort(a+1, a+7); sort(b+1, b+7);
    int ta=1, tb=1;
    int tie=0, win=0;
    for(int tb=1; tb<=6; tb++){
        ta=1;
        while(a[ta]<b[tb]) ta++;
        while(a[ta]==b[tb]) { ta++; tie++;}
        while(ta<=6){ ta++; win++;}
    }
    printf("%.5f\n", (double)win/(36-tie));
    return 0;
}
