/**
 * Author: maharshi95
 */

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n)           for(int i=0; i<n; i++)
#define rep1(i, n)          for(int i=1; i<=n; i++)

#define fup(i, a, b)        for(int i=a; i<=b; i++)
#define fdown(i, a, b)      for(int i=a; i>=b; i--)

#define sz(a)               ((int) a.size())
#define all(a)              a.begin(), a.end()
#define sgn(n)              ((n > 0) - (n < 0))

#define iter(i, a, b, s)    for(int i=a; sgn(b-a)*i <= sgn(b-a)*b; i += s)

#define checkbit(n, b)      ((n >> b) & 1)
#define setbit(n, b)        (b |= (1 << n))
#define resetbit(n, b)      (b &= ~(1 << n))

#define pb                  push_back

#define ff                  first
#define ss                  second
#define key                 first
#define value               second
 
#define hashmap             unordered_map
#define hashset             unordered_set

#define INF                 INT_MAX
#define NINF                INT_MIN

#define MOD                 (1e9 + 7)
#define MAX_SIZE            100001

#define LEFT(i)             (2*i + 1)
#define RIGHT(i)            (2*i + 2)
#define MID(i, j)           ((i+j)/2)

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vll;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef pair<double, double> pdd;

typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;

int n, m;

void precomp() {}

vi apply(vi & A, vi & B) {
	vi C(m);
	rep(i, m) {
		C[i] = B[A[i]];
	}
	return C;
}

vi inverse(vi & A) {
	vi I(m);
	rep(i, m) {
		I[A[i]] = i;
	}
	return I;
}
 
void solve() {

	int q;
	cin >> n >> m;

	vvi P(n, vi(m));

	rep(i, n) {
		rep(j, m){
			cin >> P[i][j];
			P[i][j]--;
			// cout << P[i][j] << " ";
		}
		// cout << endl;
	}

	vvi C(n+1, vi(m));
	vvi I(n+1, vi(m));

	rep(i, m) {
		C[0][i] = I[0][i] = i;
	}

	rep1(i, n) {
		C[i] = apply(C[i-1], P[i-1]);
		I[i] = inverse(C[i]);
	}

	// cout << "P: " << endl;
	// rep(i, n) {
	// 	rep(j, m) {
	// 		cout << P[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	// cout << "C: " << endl;
	// rep(i, n+1) {
	// 	rep(j, m) {
	// 		cout << C[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;


	// cout << "I: " << endl;
	// rep(i, n+1) {
	// 	rep(j, m) {
	// 		cout << I[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	cin >> q;

	if(m < n) {
		rep(qi, q) {
			int l, r;
			cin >> l >> r;
			vi B = apply(I[l-1], C[r]);
			ll sum = 0;
			rep(i, m) {
				sum += (B[i] + 1LL) * (i + 1LL);
			}
			cout << sum << endl;
		}
	} else {
		ll ANS[n+1][n+1];
		rep1(r, n) {
			rep1(l, r) {
				vi B = apply(I[l-1], C[r]);
				ll sum = 0;
				rep(i, m) {
					sum += (B[i] + 1LL) * (i + 1LL);
				}
				ANS[l][r] = sum;
			}
		}
		rep(qi, q) {
			int l, r;
			cin >> l >> r;
			cout << ANS[l][r] << endl;
		}
	}


}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
  #endif
  
  int t = 0;
    if(t == 0) cin >> t;
    precomp();
    while(t--) {
        solve();
    }

  return 0;
}