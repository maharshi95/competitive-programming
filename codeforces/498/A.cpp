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

int n, q;

vvi G;
vi L;
vi V;

int dfs(int i) {
	L[i] = 1;
	V.push_back(i);
	for(auto j: G[i]) {
		L[i] += dfs(j);
	}
	return L[i];
}

void solve() {
	cin >> n >> q;

	G.resize(n, vi());
	L.resize(n, 0);

	rep(i, n-1) {
		int p;
		cin >> p;
		G[p - 1].push_back(i + 1);
	}
	
	rep(i, n) {
		sort(all(G[i]));
	}

	dfs(0);

	// rep(i, n) {
	// 	cout << i << ": ";
	// 	for(auto u: G[i]) {
	// 		cout << u << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << V.size() << endl;

	map<int, int> mp;

	for(int i=0; i<n; i++) {
		mp[V[i]] = i;
	}

	rep(qi, q) {
		int u, k;
		cin >> u >> k;
		int index = mp[u - 1];
		if(L[u - 1] >= k) {
			cout << V[index + k - 1] + 1 << endl;
		} else {
			cout << -1 << endl;
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
  
  int t = 1;
    if(t == 0) cin >> t;
    precomp();
    while(t--) {
        solve();
    }

  return 0;
}