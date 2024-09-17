// Problem: Heap Operations
// URL: https://codeforces.com/gym/329293/problem/B
// Rating: 1600
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<int, int>> ans;
multiset<int> s;
char a[20];

int main(){
    scanf("%d", &n);
    int num;
    for(int i=1; i<=n; i++){
        scanf("%s%d", &a, &num);
        if(a[0]=='i'){
            ans.push_back(make_pair(1, num));
            s.insert(num);
        }
        else if(a[0]=='g'){
            while(!s.empty() && (*s.begin())<num){
                ans.push_back(make_pair(3, 0));
                s.erase(s.begin());
            }
            if(s.empty() || (*s.begin())>num){
                ans.push_back(make_pair(1, num));
                s.insert(num);
            }
            ans.push_back(make_pair(2, num));
        }
        else{
            if(s.empty()){
                ans.push_back(make_pair(1, 1));
                s.insert(1);
            }
            ans.push_back(make_pair(3, 0));
            s.erase(s.begin());
        }
    }
    printf("%d\n", ans.size());
    for(auto x:ans){
        if(x.first==1) printf("insert %d\n", x.second);
        else if(x.first==2) printf("getMin %d\n", x.second);
        else printf("removeMin\n");
    }
    return 0;
}