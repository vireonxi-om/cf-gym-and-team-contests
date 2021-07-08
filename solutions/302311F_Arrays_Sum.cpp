// Problem: Arrays Sum
// URL: https://codeforces.com/gym/302311/problem/F
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k, total, now, num;

void solve()
{
	scanf("%d%d", &n, &k); 
	total=0; now=-1;
	for(int i=1; i<=n; i++){
		scanf("%d", &num);
		if(num!=now){
			now=num; total++;
		}
	}
	if(k==1){
		if(total==1) printf("%d\n", 1);
		else printf("%d\n", -1);
	} 
	else{
		if(total==1) printf("%d\n", 1);
		else printf("%d\n", (total-2)/(k-1)+1);
	}
	
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++) solve();
	return 0;
} 
