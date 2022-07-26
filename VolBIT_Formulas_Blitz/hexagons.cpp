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

int main() {
    fio;
    ll n;
    cin >> n;
    /** Notice that the cell at the epicentre of the effect is also counted and has a distance of 0, so add 1.
     * From k = 1, the number of cells that are a distance of k away from the effect is the same as the perimeter
     * of a regular hexagon with side lengths of k (think of each unit as being replaced by a cell). This means
     * the total number of cells affected that are k units away from the effect is 6 * k. This means that the answer
     * for the number of cells that are at most n units away is 1 + 6 + 6 * 2 + 6 * 3 + ... + 6 * (n - 1) + 6 * n.
     * Notice that the 6 can be factored out from the rest of the sum, resulting in the following:
     *
     * 1 + 6 * [1 + 2 + 3 + ... + (n - 1) + n]
     *
     * The bracketed expression is the sum of all natural numbers from 1 to n, which can be replaced by
     * [(n + 1) * n] / 2. This number is always whole because an even number is proceeded by an odd number, and vice
     * versa. In our case:
     *
     * Total = 1 + 6 * (n + 1) * n / 2
     * = 1 + 3 * (n + 1) * n
     *
     * Make sure to use long long because n can be up to 10^9.
     *
     */
    cout << 3 * (n + 1) * (n) + 1;
    return 0;
}