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
     * For this one, note that 4 rotations of 90 degrees is a 360-degree rotation, which is the same as zero rotations.
     * This also means that some angle displacement of x and an angle displacement of x + 360 both would have the same
     * answer. By this logic, take x % 360 to limit the value to [-359, 359], then add 360 to it to make the value
     * inside [1, 719], then take modulo 360 again to get [0, 359], then see how many rotations would be needed. The
     * only issue now is that each final position of the camera is optimal for angle differences within (-45, 45] of a
     * multiple of 90 degrees. For example, one 90-degree rotation is has the best coverage for x in (46, 135] after
     * the modulo operations. As such, 0 degrees is best for [315, 45], 90 for [46, 135], 180 for [136, 225], 270 for
     * [226, 314]. Even though there might be a mathematical relationship that can be followed, an if statement works
     * just as well in a programming contest.
     *
     */
    ll x;
    int ans = 0;
    cin >> x;
    x = ((x % 360) + 360) % 360;
    if (x > 45 && x <= 135) {
        ans = 1;
    } else if (x > 135 && x <= 225) {
        ans = 2;
    } else if (x > 225 && x < 315) {
        ans = 3;
    }
    cout << ans << edl;
    return 0;
}