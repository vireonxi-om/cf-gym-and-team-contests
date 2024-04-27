// Problem: Chocolate Bunny
// URL: https://codeforces.com/gym/306200/problem/A
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int p[11000];

int main(){
    int n;
    scanf("%d", &n);
    bool conti=true;
    int j, k;
    vector<int> remain;
    for(int i=1; i<=n; i++) remain.push_back(i);
    vector<int>::iterator it=remain.begin(), ed=remain.end()-1, bg=remain.begin();
    while(conti){
        if(it==ed) {
            p[*it]=n; conti=false;
        }
        else{
            for(it=remain.begin(); it<ed; it+=2){
                printf("? %d %d\n", *it, *(it+1));
                fflush(stdout);
                scanf("%d", &j);
                printf("? %d %d\n", *(it+1), *it);
                fflush(stdout);
                scanf("%d", &k);
                if(j>k){
                    p[*it]=j;
                    *bg=*(it+1); bg++;
                }
                else{
                    p[*(it+1)]=k;
                    *bg=*it; bg++;
                }
            }
            if(it==ed){
                *bg=*it;
                ed=bg;
            }
            else ed=bg-1;
            it=remain.begin(); bg=remain.begin();
        }
    }
    printf("! ");
    for(int i=1; i<=n; i++) printf("%d ", p[i]);
    printf("\n");
    return 0;
}
