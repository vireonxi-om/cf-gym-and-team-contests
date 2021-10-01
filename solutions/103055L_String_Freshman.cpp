// Problem: String Freshman
// URL: https://codeforces.com/gym/103055/problem/L
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m;
char s[110000];

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    scanf("%d%s", &m, &s);
    auto a=prefix_function(s);
    bool can=true;
    for(int i=1; i<m; i++) if(a[i]>0) can=false;
    if(!can) printf("Wrong Answer\n");
    else printf("Correct\n");
    return 0;
}

