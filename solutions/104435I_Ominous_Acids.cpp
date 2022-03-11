// Problem: Ominous Acids
// URL: https://codeforces.com/gym/104435/problem/I
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 110000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-10;
const double pi = acos(-1.0);

int n; 

int main() {
	cin >> n;
	if (n >= 7) {
		cout << "Ignominious\n";
		return 0;
	}
	cout << "Ominous\n";
	if (n == 1) {
		cout << "1 1\nA\n";
	}
	else if (n == 2) {
		cout << "1 2\n";
		cout << "AA\n";
	}
	else if (n == 3) {
		cout << "9 4\n";
		cout << "OOOH\nWAAH\nWOAH\nWOOT\nHUTT\nHUUY\nHEYY\nWEEB\nWWBB\n";
	}
	else if (n == 4) {
		cout << "8 5\n";
		cout << "ABBBC\nAABCC\nBADCE\nBDDDE\nBBAEE\nCCAAA\nCCBBB\nDDDDB\n";
	}
	else if (n == 5){
	    cout << "6 20\n";
	    cout << "AABCCCDDDDEFFFGGHIII\n";
	    cout << "ABBBCCDJJEEEFGGKHHHI\n";
	    cout << "AABLLLLLJJJEFGKKKKHI\n";
	    cout << "UUUTSSRRRQPPPPOOONMM\n";
	    cout << "UTTTKSSRQQQJJPOONNNM\n";
	    cout << "UTKKKKSRQJJJLLLLLNMM\n";
	}
	else {
		cout << "5 72\n";
		cout << "AADDDFFFFJJJJLLNNPPRRTTTTTVVVXXAABBCEEEIIIKKKKKKPQQSSUUVVVZZZZZAACEFFFFF\n";
		cout << "AAADDFFGIIIJJLNNNOPPRSTSVVVXXXAABBCCEEIIJIJLLLNNPPQQSSUUUVVVYZYACCEEEEGF\n";
		cout << "BBADCGGGGGILLLMMNOPQRSSSSUWXYAAZBCCDEFGGJJJLMLLNOPPQRSSTUWXYYYYABCCEGGGG\n";
		cout << "BBCCCEEHHHIIKKKMMOPQRRUUUUWWYZZZBDCDFFFGHHJMMMMNOPOQRRRTWWXXXXAABCDDDDGH\n";
		cout << "BBCCEEEEHHHKKKMMOOOQQQQUWWWYYYYZZDDDFFGGGHHHHMNNOOORRTTTTWWWXBBBBDDHHHHH\n";
	}
	return 0;
}
