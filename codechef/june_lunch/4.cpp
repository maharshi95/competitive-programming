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


void precomp() {}

int num_inversions(vi & B) {
	int cnt = 0;
	for(int i=0; i<sz(B); ++i) {
		for(int j=i+1; j<sz(B); ++j) {
			if(B[i] > B[j]) {
				cnt++;
			}
		}
	}
	return cnt;
}
 
void solve() {
	int n, k, p;
	cin >> n >> k >> p;
	vi A(n);
	rep(i, n) {
		cin >> A[i];
	}

	vector<ii> pairs;
	for(int x=0; x<(1 << k); ++x) {
		vi B(n);
		rep(i, n) {
			B[i] = (A[i] ^ x);
		}
		int fx = num_inversions(B);
		pairs.push_back({fx, x});
	}
	// for(auto pa: pairs) {
	// 	cout << pa.ff << " " << pa.ss << endl;
	// }
	sort(all(pairs));
	cout << pairs[p - 1].ss << endl;
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