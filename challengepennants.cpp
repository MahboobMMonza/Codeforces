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
     * The key thing to note here is that the distribution of each of the bug pennants can be viewed independently from
     * the distribution of the feature pennants, but then when combining the two, it becomes a product the number of
     * distributions of the bug pennants and the number of distributions of the feature pennants. This is because for
     * each possible distribution of the bug pennants, any distribution of the feature pennants can occur, and vice
     * versa. There is a formula for computing the number of distributions of k identical items amongst n possible
     * candidates, but it will require further elaboration and the nature of this problem suggests knowledge of this
     * formula essentially as a prerequisite. The formula can be described as the binomial coefficient of (k + n - 1)
     * and (n - 1), or (k + n - 1) choose (n - 1). Replace k with 3 and 5 for the pennants and then expand and cancel
     * the factorials to get computable values. Multiply the results for k = 3 and k = 5 together for the answer. The
     * values can get quite large, so make sure to compute each binomial coefficient separately to prevent overflow.
     *
     */
    ull n;
    cin >> n;
    cout << (n * (n + 1ULL) * (n + 2ULL) / 6ULL) * (((n + 4ULL) * (n + 3ULL) * (n + 2ULL) * (n + 1ULL) * n) / 120ULL);
    return 0;
}