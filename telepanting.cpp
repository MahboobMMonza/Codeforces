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
typedef long double ld;
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
    /**
     * Notice that whenever the ant passes a portal and does not get teleported, the portal was initially closed and is
     * therefore opened. This means all portals BEHIND the ant are open at any given time. This means that whenever
     * the ant is teleported back to some location l, it will also be teleported back for any portals between l and
     * the first portal that teleported the ant, as well as subsequent intermediate portals. So, it is a good idea to
     * keep count of the cPSA (time required to return) of a teleportation for each portal. The cPSA for the ith portal
     * will be x[i] - y[i], as well as the cPSA of any portals that lie between x[i] and y[i]. This is because
     * y[i] < x[i], and so any portals between y[i] and x[i] will be open as well, causing more teleportation that adds
     * to the cPSA.
     *
     * The actual time taken for the ant to travel from 0 to x[n] + 1 is the distance between 0 and x[n] + 1, and the
     * sum of the costs of all portals that are open. This task can also be effectively broken up in steps, where each
     * step is the actual time taken to travel to the ith portal. Let dt be an array where the ith index represents
     * traveling from the (i-1)th portal to the ith portal and the ith portal is closed. That is, if the ith portal is
     * initially open, dt[i] is the time taken to reach it after it has been closed. For i = 1, this is just the time
     * taken to reach the first portal when it is closed. The total time taken is therefore just the sum dt[1] to dt[n],
     * because in order to reach a distance of x[n] + 1, the portal at x[n] must be shut off, and in order to reach that
     * portal, the portal at x[n - 1] needs to be passed, so it must be shut off, and so on so forth until x[1]. This
     * breakdown permits the computation of the cPSA for the ith portal as well as the total time taken to reach the ith
     * portal in an array t simultaneously.
     *
     * The cPSA computation can become redundant to compute: the ith portal sends the ant to a location y[i], and if
     * the next portal from y[i] is located at x[j], then cPSA[i] would need to sum the values of cPSA[j] up to
     * cPSA[i - 1]. Repeatedly summing across a range is O(n^2) worst-case. To fix this, a prefix-sum array cPSA can be
     * used, coupled with a binary search to find the index j. Then, cPSA[i] = x[i] - y[i] + cPSA[i - 1] - cPSA[j - 1],
     * and then cPSA[i] = cPSA[i] + cPSA[i - 1]. The former calculation could be used if the ith portal is open, adding
     * it to the total time taken to reach the ith portal when it is closed, or ignored if the portal is already closed.
     * To save memory, the ith index of cPSA will be treated as cost[i] for the time calculation, and will then have
     * cPSA[i - 1] added to it.
     *
     * This solution requires iterating through the n portals and completing a binary search on up to n elements at each
     * iteration to calculate cPSA[i], so the total time complexity is O(nlog(n)).
     */
    ll m = 998244353, ans = -1, pen = 0;
    const size_t sz = 2e5 + 1;
    vector<ll> x(sz), y(sz), cPSA(sz), t(sz);
    bitset<sz> s;
    int n, si;
    // t[i] is the total time to reach the ith portal when the ith portal is shut off
    // t[i] = t[i - 1] + x[i] - x[i - 1] + cPSA[i]
    cin >> n;
    forae(i, 1, n, 1) {
        cin >> x[i] >> y[i] >> si;
        s[i] = (bool) si;
    }
    cPSA[1] = (x[1] - y[1]) % m;
    t[1] = (x[1] + s[1] * cPSA[1]) % m;
    forae(i, 2, n, 1) {
        cPSA[i] = (x[i] - y[i]) % m;
        // Finding the index of the first portal located after y[i]
        auto l = lower_bound(x.begin() + 1, x.begin() + i, y[i]);
        pen = 0;
        if (l != x.begin() + i) {
            pen = l - x.begin() - 1;
            cPSA[i] = (cPSA[i] + cPSA[i - 1] - cPSA[pen]) % m;
        }
        t[i] = ((t[i - 1] + x[i] - x[i - 1]) % m + cPSA[i] * s[i]) % m;
        // Make PSA for cost
        cPSA[i] = (cPSA[i] + cPSA[i - 1]) % m;

    }
    ans = (t[n] + 1) % m;
    ans += (ans < 0) ? m : 0;
    cout << ans;
    return 0;
}