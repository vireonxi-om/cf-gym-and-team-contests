// Problem: Tell Your World
// URL: https://codeforces.com/gym/320373/problem/C
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
double a[1100];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lf", &a[i]);
    double k1=(a[2]-a[1]), k2=a[3]-a[2], k3=(a[3]-a[1])/2;
    bool can=true;
    if(k2==k1){
        int pos=-1;
        bool yes=true;
        for(int i=4; i<=n; i++){
            double t1=(a[i]-a[1])/(i-1);
            if(t1!=k1){
                if(pos==-1){
                    pos=i;
                }
                else{
                    double t2=(a[i]-a[pos])/(i-pos);
                    if(t2!=k1) yes=false;
                }
            }
        }
        if(pos==-1 || yes==false) can=false;
    }
    else{
        bool yes1=true, yes2=true, yes3=true;
        for(int i=4; i<=n; i++){
            double t1, t2, t3;
            t1=(a[i]-a[1])/(i-1);
            t2=(a[i]-a[2])/(i-2);
            t3=(a[i]-a[3])/(i-3);
            if(t1!=k1 && t3!=k1) {yes1=false; }
            if(t2!=k2 && t1!=k2) {yes2=false; }
            if(t3!=k3 && t2!=k3) {yes3=false; }
            if((!yes1) && (!yes2) && (!yes3)){ can=false; break;}
        }
    }
    if(can) printf("YES\n");
    else printf("NO\n");
}

