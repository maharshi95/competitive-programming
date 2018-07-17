/**
 * Author: maharshi95
 */

#include <bits/stdc++.h>

using namespace std;

#define rep0(i, n)          for(int i=0; i<n; i++)
#define rep1(i, n)          for(int i=1; i<=n; i++)

#define fup(i, a, b)        for(int i=a; i<=b; i++)
#define fdown(i, a, b)      for(int i=a; i>=b; i++)

#define sz(a)               ((int) a.size())
#define all(a)              a.begin(), a.end()
#define sgn(n)              ((n > 0) - (n < 0))

#define INF                 INT_MAX
#define NINF                INT_MIN

#define MOD                 (1e9 + 7)
#define MAX_SIZE            100001

typedef long long ll;

// Vector Snippets
#define pb                  push_back

typedef vector<int> vi;
typedef vector<ll> vll;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

vvi build_graph(int n, int m) {
  vvi G(n+1, vi());
  
  int u, v;
  for(int i = 0; i < m; i++)
  {  
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  return G;
}


void precomp() {}

void solve() {
  int n;
  cin >> n;
  int sum = 0;

  rep0(i, n) {
    int num;
    cin >> num;
    sum += i * num / (i + 1);
  }
  cout << sum << endl;
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #endif
  
  int t = 1;
    if(t == 0) cin >> t;
    precomp();
    while(t--) {
        solve();
    }

  return 0;
}