// Problem: Repair the Artwork
// URL: https://codeforces.com/gym/104270/problem/G
// Rating: unrated
// Tags: none (gym/team contest)
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = (n) - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110;
const int M = 11000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand
namespace NT{
template <typename T>
T inverse(T a, T m) {
  	T u = 0, v = 1;
  	while (a != 0) {
    	T t = m / a;
    	m -= t * a; swap(a, m);
    	u -= t * v; swap(u, v);
  	}
  	assert(m == 1);
  	return u;
}
 
template <typename T>
class Modular {
public:
	using Type = typename decay<decltype(T::value)>::type;
 
  	constexpr Modular() : value() {}
  	template <typename U>
  	Modular(const U& x) {
    	value = normalize(x);
  	}
 
  	template <typename U>
  	static Type normalize(const U& x) {
    	Type v;
    	if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    	else v = static_cast<Type>(x % mod());
    	if (v < 0) v += mod();
    	return v;
  	}
 
  	const Type& operator()() const { return value; }
  	template <typename U>
  	explicit operator U() const { return static_cast<U>(value); }
  	constexpr static Type mod() { return T::value; }
 
  	Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  	Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  	template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  	template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  	Modular& operator++() { return *this += 1; }
  	Modular& operator--() { return *this -= 1; }
  	Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  	Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  	Modular operator-() const { return Modular(-value); }
 
  	template <typename U = T>
  	typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
	    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
	    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
	    asm(
	      "divl %4; \n\t"
	      : "=a" (d), "=d" (m)
	      : "d" (xh), "a" (xl), "r" (mod())
	    );
    	value = m;
#else
    	value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    	return *this;
  	}
  	template <typename U = T>
  	typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    	long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    	value = normalize(value * rhs.value - q * mod());
    	return *this;
  	}
  	template <typename U = T>
  	typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    	value = normalize(value * rhs.value);
    	return *this;
  	}
 
  	Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  	friend const Type& abs(const Modular& x) { return x.value; }
 
  	template <typename U>
  	friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  	template <typename U>
  	friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  	template <typename V, typename U>
  	friend V& operator>>(V& stream, Modular<U>& number);
 
private:
  	Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  	assert(b >= 0);
  	Modular<T> x = a, res = 1;
  	U p = b;
  	while (p > 0) {
    	if (p & 1) res *= x;
    	x *= x;
    	p >>= 1;
  	}
  	return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
	return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  	return to_string(number());
}
 
// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  	return stream << number();
}
 
// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  	typename common_type<typename Modular<T>::Type, long long>::type x;
  	stream >> x;
  	number.value = Modular<T>::normalize(x);
  	return stream;
}
};
using Mint=NT::Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;

int T, n, m, a[N];
Mint dp[2][2][N][M], ans;
Mint pow_mod(Mint a, LL e) {
	Mint res = 1;
	for (; e; a = a * a, e >>= 1) if (e & 1) res = res * a;
	return res;
}
int main() {
	IO;
	cin >> T;
	// T = 1000;
	while (T--) {
		cin >> n >> m;
		repn(i, 1, n) cin >> a[i];
		// if (T <= 50) n = 100, m = inf;
		// else n = 50, m = inf;
		// repn(i, 1, n) a[i] = 2;
		a[0] = a[n + 1] = 1;
		rep(i, 0, 2) rep(j, 0, 2) repn(k, 0, n) repn(l, 0, n * n) dp[i][j][k][l] = 0;
		int p = 0;
		dp[0][0][0][0] = 1;
		repn(i, 1, n + 1) {
			rep(j, 0, 2) repn(k, 0, i) repn(l, 0, i * (i + 1) / 2) dp[p ^ 1][j][k][l] = 0;
			int lim1 = i - 1, lim2 = (i - 1) * i / 2;
			rep(j, 0, 2) repn(k, 0, lim1) repn(l, 0, lim2) {
				if (dp[p][j][k][l] == 0) continue;
				if (a[i] == 0) {
					dp[p ^ 1][j][k + 1][l] += dp[p][j][k][l];
				}
				else if (a[i] == 1) {
					dp[p ^ 1][j][0][l + k * (k + 1) / 2] += dp[p][j][k][l];
				}
				else if (a[i] == 2) {
					// ignore
					dp[p ^ 1][j][k + 1][l] += dp[p][j][k][l];
					// select
					dp[p ^ 1][j ^ 1][0][l + k * (k + 1) / 2] += dp[p][j][k][l];
				}
			}
			p ^= 1;
		}
		ans = 0;
		repn(i, 0, n * n) {
			ans = ans + dp[p][0][0][i] * pow_mod(i, m) - dp[p][1][0][i] * pow_mod(i, m);
		}
		cout << ans << "\n";
	}
	return 0;
}