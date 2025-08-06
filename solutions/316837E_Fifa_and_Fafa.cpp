// Problem: Fifa and Fafa
// URL: https://codeforces.com/gym/316837/problem/E
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
double r, x, y, a, b, ans, ax, ay;

int main(){
    scanf("%lf%lf%lf%lf%lf", &r, &x, &y, &a, &b);
    double d=sqrt((a-x)*(a-x)+(b-y)*(b-y));
    if(d-r>=-1e-8){
        ax=x; ay=y; ans=r;
    }
    else{

        ans=(r+d)/2;if(x==a && y==b){ ax=x+ans; ay=y;}
        else{
            ax=a+(x-a)*ans/d;
            ay=b+(y-b)*ans/d;
        }

    }
    printf("%.10f %.10f %.10f\n", ax, ay, ans);
    return 0;
}
