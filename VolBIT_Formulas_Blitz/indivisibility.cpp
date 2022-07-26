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
    /**
     * The brute force implementation will over-count all possible values, since there are some overlaps. Notice that
     * all the even numbers are accounted for by subtracting the number of even numbers in [1, n] from n. Next, doing
     * this for all multiples of 3 accounts for 3, 6, and 9. 6 was subtracted already, so the number of multiples of 6
     * should be ADDED in. Subtracting the multiples of 5 covers all multiples of 5, 10 and 15, but 10 and 15 were again
     * accounted for with the even numbers and multiples of 3, so ADD all multiples of 10 and 15, but then subtract all
     * multiples of 30. Do the subtraction again for all multiples of 7. However, add in the multiples of 14, then 21,
     * since they were double counted. Then subtract the multiples of 42 (7 * 2 * 3), since they will be added back
     * twice. Then do this again with 35, but add back in the multiples of 70 (7 * 5 * 2) and 105 (7 * 5 * 3) since they
     * would be double counted, but then the multiples of 210 (7 * 2 * 3 * 5) would be added back twice instead of once,
     * so subtract them.
     *
     */
    ull n;
    cin >> n;
    cout << n - (n / 2) - (n / 3) + (n / 6) - (n / 5) + (n / 10) + (n / 15) - (n / 30) - (n / 7) + (n / 14) + (n / 21) -
            (n / 42) + (n / 35) - (n / 70) - (n / 105) + (n / 210) << edl;
    return 0;
}