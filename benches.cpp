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
     * There are n^2 choices for the first location, and then the entire East/West and North/South road pair is
     * eliminated, meaning the rest of the viable intersection come from (n - 1) EW roads and (n - 1) NS roads, or
     * (n - 1)^2 choices for the next location. Similarly, there are now (n - 2)^2 choices for the 3rd location,
     * (n - 3)^2 for the fourth, and (n - 4)^2 choices for the fifth. There are 5! permutations of these choices, so
     * divide by 120 at the end. Notice that (n^2 * (n - 1)^2 * (n - 2)^2 * (n - 3)^2 * (n - 4)^2) is just the square.
     * of the binomial coefficient for k = 5. So, compute the binomial coefficient first, then divide by 120, then
     * multiply it by the binomial coefficient again.
     *
     */
    ull n;
    cin >> n;
    cout << (n * (n - 1ULL) * (n - 2ULL) * (n - 3ULL) * (n - 4ULL)) / 120ULL * (n * (n - 1ULL) * (n - 2ULL) * (n - 3ULL) * (n - 4ULL)) << edl;
    return 0;
}