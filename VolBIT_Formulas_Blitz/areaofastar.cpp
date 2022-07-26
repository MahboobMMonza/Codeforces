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
     * To find the area of the star, break it into triangles using lines of symmetry passing through each outer vertex
     * of the star. The lines of symmetry all intersect at the centre and make angles theta = 2 * pi / (2 * n) = pi / n.
     * Let A be the first vertex on the circumference of the circle, and B be the vertex adjacent to A on the
     * circumference. If O is the centre of the circle, Then the angle AOB is 2 * theta. If some vertex C also on the
     * circumference is placed opposite to A and B, then there is a property of a circle that states that an angle
     * subtended at the centre of a circle is twice any angle subtended on any other part. This means angle ACB is also
     * theta, and since the star is "regular", any angle formed by a vertex of the star on the circumference of the
     * circle is also theta. Taking the lines of symmetry, a segment from the vertex to the centre would bisect this
     * angle, making it theta / 2. A triangle can be formed connecting a vertex on the circumference to the centre, as
     * well as the closest convex-angle vertex of the star. The angle at that point would be pi - theta / 2 - theta,
     * or pi - 1.5 * theta. Using the law of sines, one of the sides of the triangle that is not formed by the radius
     * can be found, for simplicity's sake make this the shortest side of the triangle, and then that can be used with
     * sin(theta) to find the height of the triangle, and the area of the triangle would be r * h / 2. There are 2 * p
     * triangles formed like this, all of which are congruent, so total area of the star is 2 * n * r * h / 2, which is
     * n * r * h when simplified. Here, once the short side is found, multiplying by sin(theta) when finding the total
     * area suffices for h. Use long double to maintain precision and sign.
     *
     */
    cout << setprecision(15);
    ll n, r;
    cin >> n >> r;
    long double pi = acos(-1);
    long double theta = pi / n;
    long double obtuse = pi - (1.5 * theta);
    long double c = r * sin(theta / 2) / sin(obtuse);
    cout << n * r * c * sin(theta) << edl;
    return 0;
}