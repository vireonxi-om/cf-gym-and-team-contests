// Problem: Copying Homework
// URL: https://codeforces.com/problemset/problem/1252/A
// Rating: 1000
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;


#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define repn(i, a, n) for (int i = a; i <= n; i++)
const int N = 110000;
int n, a[N];
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		cin >> a[i];
		if (a[i] != n) cout << a[i] + 1;
		else cout << 1;
		if (i != n) cout << " ";
		else cout << "\n";
	}
	return 0;
}