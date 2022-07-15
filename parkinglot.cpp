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
     * Every n-value can be considered to have:
     * 2 cases where one of the cars in the cluster is at the edge
     * 0 or more cases where there are cars not directly beside the cluster
     *
     * 2n - 2 parking spots with n taken leaves n - 2 spots for other cars
     * Of that, up to 2 spots are directly adjacent to the cluster, and those cars cannot be of the same make
     * Unless the cluster is at the beginning or end of the lot, there are n - 4 spots not adjacent to the cluster
     * In general, this means that the total number of possibilities is broken up as follows:
     * Number of combinations where the cluster is not at either edge (call c_m) + 2 * cluster at the edge (call c_e)
     *
     * Cluster at the edge breaks down to product of following:
     * Makes of cluster (4)
     * Makes of adjacent car (3)
     * Combination of makes of remaining cars (4^(n - 3))
     *
     * c_e = 4 * 3 * 4^(n - 3) = 3 * 4^(n - 2)
     *
     * Cluster in the middle can be rearranged to be adjacent-cluster-adjacent-remaining_cars without loss of generality
     * as long as all the actual number of possible positions for the cluster are accounted for. This calculation can be
     * derived using the following logic:
     * Imagine placing the cluster at the end of the lot (i.e. the last car of the cluster is at the last position of
     * the lot). This is one possible location for the cluster, but it is also when the cluster is at the edge. Of the
     * 2n - 2 spots, n are taken and n - 2 spots remain. The cluster could also have started from one of those n - 2
     * spots, meaning in total there are 1 + n - 2 = n - 1 spots to place the cluster, but 2 of those spots are at the
     * edge, so n - 3 possible locations remain for the cluster to be located while not touching an edge spot.
     *
     * This breaks down c_m as a product of the following:
     * Cluster locations (n - 3)
     * Makes of the cluster (4)
     * Makes of the 2 adjacent cars (3^2)
     * Combination of makes of remaining cars (4^(n - 4))
     *
     * c_m = (n - 3) * 4 * 9 * 4^(n - 4) = (n - 3) * 9 * 4^(n - 3)
     *
     * Number of combinations possible = c_m + 2 * c_e
     * = (n - 3) * 9 * 4^(n - 3) + 2 * 3 * 4^(n - 2)
     * = (n - 3) * 9 * (2^2)^(n - 3) + 2 * 3 * (2^2)^(n - 2)
     * = (n - 3) * 9 * 2^(2n - 6) + 2 * 3 * 2^(2n - 4)
     * = (n - 3) * 3^2 * 2^(2n - 6) + 3 * 2^(2n - 3)
     * = [2^(2n - 6) * 3] * [(n - 3) * 3 + 8]
     * = [2^(2n - 6) * 3] * [(n - 3) * 3 + 8]
     * Factored the edge case scenario * n-3*6 middle scenarios
     *
     * This mathematical factoring will reduce the total number of computations we need to do, as we can use
     * bit shifting to exploit an operation of 2 ^ k.
     *
     */
    ull n, pow = 1, ans = 0;
    cin >> n;
    pow <<= 2 * n - 6;
    // cout << ((pow<<(2*n-6)) * 3) << edl;
    ans = (pow * 3) * ((n - 3) * 3 + 8);
    cout << ans << edl;
    return 0;
}
