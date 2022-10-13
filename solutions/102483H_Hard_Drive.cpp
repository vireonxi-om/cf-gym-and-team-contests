// Problem: Hard Drive
// URL: https://codeforces.com/gym/102483/problem/H
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, c, b;
    cin >> n >> c >> b;
    vector<int> broken;
    int ans[n];
    memset(ans, 0, sizeof(ans));
    for(int i=0; i<b; i++){
        int tmp;
        cin >> tmp;
        broken.push_back(tmp-1);
    }
    if(c%2==0) {ans[0] = 0;broken.insert(broken.begin(), 0);}
    else {ans[0] = 1; c--; if(n>2) broken.insert(broken.begin(), 1);}
    for(int i=0; i<broken.size()-1;i++){
        int cur = broken[i]+1;
        while(c>0 && cur<broken[i+1])
        {
            ans[cur] = ans[cur-1] ^ 1;
            ans[cur+1] = ans[cur] ^ 1;
            c-=2;
            cur+=2;
        }
    }
    for(int i=0; i<n;i++) cout<<ans[i];
}