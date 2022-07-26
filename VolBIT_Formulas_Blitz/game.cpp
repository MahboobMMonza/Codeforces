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
    ll n;
    /**
     * Since the game is played on a square board, think of an n x n chequered board. This is the optimal configuration
     * for any size n if each player plays optimally. If n is odd, then there is one more black tile available on the
     * chequered board, so player 1 wins. If n is even, then there are an equal number of black tiles, so player 2 wins.
     * Since player one always goes first, if n is odd, then player 1 can always take the centre tile. After that, there
     * are an even number of both black and non-black tiles left on the board, so regardless of whether or not player 2
     * chooses to play on the traditionally black or non-black tiles, player 1 can always reciprocate a move such that
     * they can make the last move by tactically choosing tiles that are the same colour as what player 2 played. If n
     * is even, then regardless of what tile colour player 1 starts with, player 2 can keep the same colour as player 1
     * and always get the last move. Note that colour here refers to the assignment a tile would get in a traditional
     * n x n chequered pattern. If the losing player chooses to switch, they limit themselves to just less moves in
     * total, but there will be 4 less potential spots to choose from, which still maintains an even number of spots, so
     * for even n, this means that player 2 will always move last, and for odd n, player 1 gets last move. x % 2 is 0
     * for even numbers, and 1 for odd numbers. This means that (x - 1) % 2 is 1 if x is even since x - 1 is odd, and
     * (x - 1) % 2 is 0 if x is odd. From that value, just add 1. Using bitwise and with 1 yields similar results,
     * except that x & 1 is 1 if x is odd, and 0 if it is even. Subtracting 1 performs the same shift as the mod 2
     * example.
     *
     */
    cin >> n;
    cout << ((n - 1)&1) + 1 << edl;
    return 0;
}