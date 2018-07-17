/**
 * Author: maharshi95
 */

#include <bits/stdc++.h>

using namespace std;

#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)

#define fup(i, a, b) for (int i = a; i <= b; i++)
#define fdown(i, a, b) for (int i = a; i >= b; i++)

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define sgn(n) ((n > 0) - (n < 0))

#define INF INT_MAX
#define NINF INT_MIN

#define MOD (1e9 + 7)
#define MAX_SIZE 100001

typedef long long ll;

// Vector Snippets
#define pb push_back

typedef vector<int> vi;
typedef vector<ll> vll;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

bool have_same_primes(ll x, ll y)
{
    while(y > 1 && x > 1) {
        x = __gcd(x, y);
        y = y / x;
    }
    return true;
}

void solve()
{
    ll p, q, b;
    cin >> p >> q >> b;
    
    q /= __gcd(p, q);
    
    if(p == 0 || have_same_primes(b, q)) {
        cout << "Finite" << endl;
    } else {
        cout << "Infinite" << endl;
    }
}

void precomp() {
    // cout << same_primes(100, 65526 * 5) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    int t = 0;
    if(t == 0) cin >> t;
    precomp();
    while (t--)
    {
        solve();
    }

    return 0;
}