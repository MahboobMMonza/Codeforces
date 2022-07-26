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

pair<ld, ld> scalar_multiplication(ld k, pair<ld, ld> vc) {
    return {k * vc.fs, k * vc.sc};
}

pair<ld, ld> add_vectors(pair<ld, ld> a, pair<ld, ld> b) {
    return {a.fs + b.fs, a.sc + b.sc};
}

int main() {
    fio;
    /**
     * To find each of the coordinates, the vector and its perpendicular vector in 2-space are required. In 2-space, a
     * vector's perpendicular can be found by switching the x and y values and changing one of the values to its
     * negative. Using the variable names given in the program, if (vx, vy) were given as (-1, -2), then its
     * perpendicular would be (2, -1). This can be confirmed as the dot product of (vx, vy) and (-vy, vx) is 0. Then the
     * vectors can be normalized, and since the scalars are given with respect to the base, they are in fact in the same
     * direction as either the given vector (in the case of b and d) or the perpendicular vector (in the case of a and
     * c). This means that b * (vx, vy) + (px, py) after normalization gives the coordinates of the tip, and
     * (a / 2) * (-vy, vx) + (px, py) would give one of the other vertices of the triangle, while multiplication with
     * (-a / 2) would give the other. To find the bottom corners of the rectangle, one would be -d * (vx, vy) + (c / 2) *
     * (-vy, vx) + (px, py), while the other would use (-c / 2) instead. To find the top corners of the rectangle, the
     * same process as finding the bottom corner can be used, except there would be no contribution from the given
     * vector. Note that defining the perpendicular as (-vy, vx) creates the perpendicular counter-clockwise to the
     * given vector, whereas (vy, -vx) gives the perpendicular clockwise to the vector. Use long double to maintain
     * within the relative error. Some functions to facilitate scalar multiplication and vector addition were also
     * created above.
     *
     */
    int px, py, vx, vy, a, b, c, d;
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    pair<ld, ld> point(px, py), vec(vx, vy), perp(-vy, vx), tip, t1, t2, r1, rt1, rt2, r2;
    // Normalize the vectors
    ld norm = sqrt(vec.fs * vec.fs + vec.sc * vec.sc);
    vec.fs = vec.fs / norm;
    vec.sc = vec.sc / norm;
    perp.fs = perp.fs / norm;
    perp.sc = perp.sc / norm;
    tip = add_vectors(point, scalar_multiplication(b, vec));
    t1 = add_vectors(point, scalar_multiplication(0.5 * a, perp));
    t2 = add_vectors(point, scalar_multiplication(-0.5 * a, perp));
    r1 = add_vectors(point, add_vectors(scalar_multiplication(-d, vec), scalar_multiplication(0.5 * c, perp)));
    rt1 = add_vectors(point, scalar_multiplication(0.5 * c, perp));
    rt2 = add_vectors(point, scalar_multiplication(-0.5 * c, perp));
    r2 = add_vectors(point, add_vectors(scalar_multiplication(-d, vec), scalar_multiplication(-0.5 * c, perp)));
    cout << setprecision(15);
    cout << tip.fs << ' ' << tip.sc << edl;
    cout << t1.fs << ' ' << t1.sc << edl;
    cout << rt1.fs << ' ' << rt1.sc << edl;
    cout << r1.fs << ' ' << r1.sc << edl;
    cout << r2.fs << ' ' << r2.sc << edl;
    cout << rt2.fs << ' ' << rt2.sc << edl;
    cout << t2.fs << ' ' << t2.sc << edl;
    return 0;
}