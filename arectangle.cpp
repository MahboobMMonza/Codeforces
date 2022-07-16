#include <bits/stdc++.h>

using namespace std;

#define fs first
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sc second
#define pb push_back
#define eb emplace_back
#define edl '\n'
#define pf push_front
#define ppb pop_back()
#define fr front()
#define bk back()
#define sbf setbuf(stdout, 0)
#define ppf pop_front()
#define tp top()
#define ps push
#define pp pop()
#define fls fflush(stdout)
#define qu queue
#define st stack
#define pq priority_queue
#define fora(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define forae(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define ford(i, a, b, c) for (int i = (a); i > (b); i -= (c))
#define forde(i, a, b, c) for (int i = (a); i >= (b); i -= (c))

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;
typedef pair<pi, pi> ppi;
typedef pair<char, int> pci;

inline ll mulMod(ll x, ll y, ll m = LONG_LONG_MAX) {
    x %= m;
    ll res = 0;
    while (y) {
        if (y & 1) res = (res + x) % m;
        if (res < 0) res += m;
        x = (x << 1) % m;
        y >>= 1;
    }
    return res % m;
}

inline ll logPow(ll x, ll y, ll m = LONG_LONG_MAX) {
    x %= m;
    ll res = 1;
    while (y) {
        if (y & 1) res = mulMod(res, x, m);
        x = mulMod(x, x, m);
        y >>= 1;
    }
    return res % m;
}

inline ll fsLogPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

inline ll pLogPow(ll x, ll y, ll m = 9223372036854775783) { return logPow(x, y % (m - 1), m); }

int main() {
    fio;
    vector<ll> x(2, 0), y(2, 0);
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    // Shift the rectangle to have lower left hexagon centre at (0, 0)
    x[1] -= x[0];
    x[0] = 0;
    y[1] -= y[0];
    y[0] = 0;
    /**
     * The number of centres a column can have depends on whether its index is even or odd. For simplicity, using
     * 0-index, the pattern breaks down as follows:
     *
     * Let n be the number of integers from 0 to y2. The shifting we did means that the height is actually just y2 now.
     * Notice that for any given rectangle, the first column (column 0) has all its centres as even y-values.For the
     * next column, all the centres are located on odd y-values. This process repeats until the end of the rectangle,
     * which after shifting, will always end on an even x-value. So the total number of hexagons encapsulated is the sum
     * of the product of the number of even-index columns multiplied by the number of even numbers in n and the product
     * of the number of odd-index columns multiplied by the number of odd numbers in n. Since n includes 0, this needs
     * to be accounted for. The number of even numbers from 1 to n is n/2, and to include 0, which is even, just add 1
     * to this value. The number of odd numbers in the same range is just the difference of n and the number of even
     * numbers. Remember the range is inclusive of 0, so n = y2 + 1.
     *
     */
    ll h_even = y[1] / 2 + 1, even_col = x[1] / 2 + 1;
    cout << (h_even * even_col) + ((y[1] + 1 - h_even) * (x[1] + 1 - even_col)) << edl;
    return 0;
}