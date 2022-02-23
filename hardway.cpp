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
#define fora(i, a, b, c) for (int (i) = (a); (i) < (b); (i) += (c))
#define forae(i, a, b, c) for (int (i) = (a); (i) <= (b); (i) += (c))
#define ford(i, a, b, c) for (int (i) = (a); (i) > (b); (i) -= (c))
#define forde(i, a, b, c) for (int (i) = (a); (i) >= (b); (i) -= (c))
#define dblinf numeric_limits<double>::infinity()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pl;
typedef pair<ull, ull> pull;
typedef pair<int, pi> pii;
typedef pair<ll, pl> pll;
typedef pair<pi, pi> ppi;
typedef pair<double, double> pd;
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

double getSlope(const pd &a, const pd &b) {
    // Special cases
    if (a.sc == b.sc) {
        return 0;
    }
    if (a.fs == b.fs) {
        return dblinf;
    }
    // m = (y2 - y1) / (x2 - x1)
    // y1 = m * x1 + b -> b = y1 - m * x1
    double m = (b.sc - a.sc) / (b.fs - a.fs + 0.0);
    return m;
}

double getDistance(const pd &a, const pd &b) {
    return sqrt(((a.fs - b.fs) * (a.fs - b.fs)) + ((a.sc - b.sc) * (a.sc - b.sc)));
}

int main() {
    fio;
    int t;
    double ans;
    // Sort leftmost x
    vector<pi> triangle(3);
    // Slopes will be 1 -> 2, 1 -> 3, 2 -> 3
    vector<double> slopes(3);
    // distances will be 1 -> 2, 1 -> 3, 2 -> 3
    vector<double> distances(3);
    vector<int> order{0, 1, 0, 2, 1, 2};
    cin >> t;
    while (t--) {
        ans = 0;
        fora(i, 0, 3, 1) {
            cin >> triangle[i].fs >> triangle[i].sc;
        }
        sort(triangle.begin(), triangle.end());
        forae(i, 0, 4, 2) {
            slopes[i / 2] = getSlope(triangle[order[i]], triangle[order[i + 1]]);
            distances[i / 2] = getDistance(triangle[order[i]], triangle[order[i + 1]]);
        }
        fora(i, 0, 3, 1) {
            if (slopes[i] == 0) {
                // Determine if the horizontal line is at the bottom
                // This is done by determining the y-value of the non-equal one
                switch (i) {
                    case 0:
                        if (triangle[2].sc < triangle[0].sc) {
                            ans = distances[0];
                        }
                        break;
                    case 1:
                        if (triangle[1].sc < triangle[0].sc) {
                            ans = distances[1];
                        }
                        break;
                    default:
                        if (triangle[0].sc < triangle[2].sc) {
                            ans = distances[2];
                        }
                        break;
                }
                break;
            }
        }
        cout << fixed << setprecision(10) << ans << edl;
    }
    return 0;
}