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

void precomp() {}

void solve()
{
    int n, m;
    cin >> n >> m;
    int A[n][m];
    vvi M(n, vi(m, 0));

    rep0(i, n)
    {
        string s;
        cin >> s;
        
        rep0(j, m)
        {
            if (s[j] == '*')
            {
                A[i][j] = -1;

                int low_i = max(0, i - 1);
                int low_j = max(0, j - 1);
                int high_i = min(n - 1, i + 1);
                int high_j = min(m - 1, j + 1);

                fup(ki, low_i, high_i)
                {
                    fup(kj, low_j, high_j)
                    {
                        M[ki][kj]++;
                    }
                }
            }
            else
            {
                A[i][j] = (s[j] == '.' ? 0 : s[j] - '0');
            }
        }
    }
    bool valid = true;

    // cout << "A: " << endl;
    // rep0(i,n) {
    //     rep0(j, m) {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << "M: " << endl;
    // rep0(i,n) {
    //     rep0(j, m) {
    //         cout << M[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n && valid; i++)
    {
        for (int j = 0; j < m && valid; j++)
        {
            // cout << A[i][j] << " ";
            if (A[i][j] != -1 && A[i][j] != M[i][j])
            {
                // cout << i <<  " " << j << ": " << A[i][j] << ", " << M[i][j] << endl;
                valid = false;
            }
        }
        // cout << endl;
    }
    cout << (valid ? "YES" : "NO") << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    if (t == 0)
        cin >> t;
    precomp();
    while (t--)
    {
        solve();
    }

    return 0;
}