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
     * The area of a pyramid is equal to the 1/3 of the area of the base, multiplied by the height. Now, the area of a
     * triangular-based pyramid and a square-based pyramid are easy to find based on this property, but the challenge
     * arises for the pentagonal-based pyramid. For that, the area of the pentagon needs to be found. In order to do
     * that, the general formula for the area of a regular n-sided polygon can be used. The formula is n/2 * a * l,
     * where l is the side length and a is the apothem, which is the perpendicular bisector of an edge from the centroid
     * of the pentagon. In order to find that, the pentagon needs to be broken up into 5 isosceles triangles by
     * connecting the centroid to each vertex. Each connected side would have the length of the radius of a circle that
     * has each vertex of the regular polygon on its circumference, so the edges that are created all have the same
     * length and are slightly longer than the apothem since that line does not meet the circumference of the circle.
     * Another property of the created isosceles triangle is that the angle at the centre is 360 / 5 degrees, and based
     * on the setup of the isosceles triangle, the other two angles are (180 - (360 / 5)) / 2 = 54 degrees. The tan
     * ratio of this angle is a / (l / 2) = 2 * a / l. Isolating for a and substituting for it in the area formula,
     * we get l^2 * n * tan(54deg) / 4. To find the height of the pyramid, take radius of the circle formed with the
     * vertices on the circumference as the base, l as the hypotenuse, and solve pythagorean theorem for the remaining
     * side, which connects the top vertex of the pyramid to the centre of the circle and the polygon base, and is a
     * right triangle since those have overlapping x and y coordinates if plotted in 3-space with the base on the xy
     * plane. For that, the radius which was a side length for the isosceles triangle used for the pentagon area
     * calculation is required, but this time for the square and triangular-based pyramids. The cosine ratio could be
     * used for that calculation, but keep in mind that the angle in question is (180 - (360 / n)) / 2, or 90 - 180 / n.
     * Then isolate for the hypotenuse to get the value of the radius, and use that in the subsequent pythagorean
     * theorem. Finally plug all values into the formula for the volume of a pyramid. Note that the process used to find
     * the area of a regular polygon works for any n-sided polygon, so a loop can be implemented to find the areas of
     * the base and the volume and added together, even though it is not necessary. Set a higher precision to get a
     * smaller relative error.
     *
     */
     cout << setprecision(15);
     int l[3];
     for (int i = 0; i < 3; i++) {
         cin >> l[i];
     }
     double pi = acos(-1);
     double a_base, h, r, radians, volume = 0;
     for (int n = 3; n <= 5; n++) {
         radians = (90 - (180 / n)) * (pi / 180);
         a_base = (l[n - 3] * l[n - 3] / 4.0) * n * tan(radians);
         r = l[n - 3] / (2 * cos(radians));
         h = sqrt(l[n - 3] * l[n - 3] - r * r);
         volume += a_base * h / 3.0;
     }
    cout << volume << edl;
    return 0;
}