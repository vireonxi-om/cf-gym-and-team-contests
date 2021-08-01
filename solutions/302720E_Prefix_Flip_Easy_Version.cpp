// Problem: Prefix Flip (Easy Version)
// URL: https://codeforces.com/gym/302720/problem/E
// Rating: 1300
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k, a[110000], b[110000], c[210000];

void solve(){
    scanf("%d", &n);
    k=0;
    getchar();
    for (int i=1; i<=n; i++) scanf("%c", &a[i]);
    getchar();
    for (int i=1; i<=n; i++) scanf("%c", &b[i]);
    for(int i=n; i>1; i--){
        if(a[i]!=b[i]){
            if(a[1]==b[i]){
                k++; c[k]=1; a[1]=97-a[1];
                k++; c[k]=i;
                for(int j=1; j<=i/2; j++){
                    swap(a[j], a[i+1-j]);
                    a[j]=97-a[j];
                    a[i+1-j]=97-a[i+1-j];
                }
                if(i%2==1) a[i/2+1]=97-a[i/2+1];
            }
            else{
                k++;
                c[k]=i;
                a[1]=97-a[i];
                for(int j=1; j<=i/2; j++){
                    swap(a[j], a[i+1-j]);
                    a[j]=97-a[j];
                    a[i+1-j]=97-a[i+1-j];
                }
                if(i%2==1) a[i/2+1]=97-a[i/2+1];
            }
        }
    }
    if(a[1]!=b[1]){
        k++; c[k]=1;
    }
    printf("%d ", k);
    for(int i=1; i<=k; i++) printf("%d ", c[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
