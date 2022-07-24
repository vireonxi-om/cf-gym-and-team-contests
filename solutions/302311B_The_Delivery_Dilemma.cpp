// Problem: The Delivery Dilemma
// URL: https://codeforces.com/gym/302311/problem/B
// Rating: 1400
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
long long n, sum, ans;
pair<long long, long long> a[210000];

long long maxi(long a, long b){
	if(a>=b) return a;
	else return b;
}
void solve()
{
	sum=0;
	scanf("%lld", &n);
	for(int i=1; i<=n; i++) scanf("%lld", &a[i].first);
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i].second);
		sum+=a[i].second;
	}
	sort(a+1, a+n+1);
	ans=sum;
	for(int i=1; i<=n; i++){
		if(sum>a[i].first){
			ans=maxi(a[i].first,sum-a[i].second);
		    sum-=a[i].second;
		}
		else break;
	}
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++) solve();
	return 0;
 } 
