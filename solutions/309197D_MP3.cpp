// Problem: MP3
// URL: https://codeforces.com/gym/309197/problem/D
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, I, pre[410000], suf[410000];
map<int, int> a;

int pow(int a, int b){
    int result=1;
    while(b--){
        result*=a;
    }
    return result;
}

int main(){
    scanf("%d%d", &n, &I);
    for(int i=1; i<=n; i++){
        int num; scanf("%d", &num);
        a[num]++;
    }
    int p=8*I/n;
    if(p>19) {printf("0\n"); return 0;}
    int tot=pow(2, p), K=a.size();
    if(K<=tot) {printf("0\n"); return 0;}
    int result=1e9; K-=tot;
    auto l=a.begin(), r=a.end(); r--;
    for(int j=1; j<=K; j++){ pre[j]=pre[j-1]+l->second; l++; }
    for(int j=K; j>=1; j--){ suf[j]=suf[j+1]+r->second; r--;}
    for(int i=0; i<=K; i++){
        int sum=pre[i]+suf[i+1];
        result=min(result, sum);
    }
    printf("%d\n", result);
    return 0;
}
