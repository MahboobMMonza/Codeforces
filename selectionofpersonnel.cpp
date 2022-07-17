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
     * The number of unique combinations of k numbers given a choice of n numbers (n >= k) is n!/[k!(n-k)!]. This is
     * denoted as nCk. For this problem, k is either 5, 6, or 7, and the total number of groupings possible is their
     * sum. That is nC5 + nC6 + nC7. This expression can be expanded and factored to get one where less computation is
     * needed, but in turn, the values need to be tracked as numerators and denominators. The formula is derived after
     * this expansion, factoring, and common denominator is put in place. Beware of overflow that occurs due n going up
     * to 777, and 777^7 is greater than 2^64.
     *
     * nCk becomes:
     * [(n - k + 1) * (n - k + 2) * ... * (n)]/k! after expansion. Based on this, we have:
     *
     * (n * (n - 1) * (n - 2) * (n - 3) * (n - 4)) / 5! + (n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5)) / 6!
     * + (n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6)) / 7!
     *
     * From this, the portion of nC5 can be factored, making it:
     * nC5 * [1 + (n - 5) / 6 + (n - 5) * (n - 6) / 42]
     * = nC5 * [(n^2 - 4 * n + 37) / 42]
     *
     * Replace nC5 with the expanded version and do the computations separately to avoid overflowing.
     *
     */
    ull n;
    cin >> n;
    cout << (n * (n - 1ULL) * (n - 2ULL) * (n - 3ULL) * (n - 4ULL)) / (5ULL * 4ULL * 3ULL * 2ULL) * ((n * n) - (4ULL * n) + 37ULL) / 42LL << edl;
    return 0;
}