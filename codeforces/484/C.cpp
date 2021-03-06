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

#define _1                  first
#define _2                  second
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

const int max_size = 100000;

vi primes;

void precomp() {
	vector<bool> is_prime(max_size + 1, true);

	is_prime[0] = false;
	is_prime[1] = false;
	
	for(int p=2; p * p <= max_size; p++) {
		for(int num = p * 2; num <= max_size; num += p) {
			is_prime[num] = false;
		}
	}
	primes.push_back(2);
	for(int i=3; i<=max_size; i+=2) {
		if(is_prime[i])
			primes.push_back(i);
	}
}
 
void solve() {
	int s, e;
	cin >> s >> e;
	s = max(2, s);
	
	if(s > e) {
		cout << endl;
		return;
	}

	vector<bool> is_prime(e - s + 1, true);

	for(auto p: primes) {
		if(p > e) break;
		int r = (p - (s % p)) % p;
		for(int num=s+r; num <= e; num += p) {
			is_prime[num - s] = (num == p);
		}
	}
	for(int i=s; i<=e; i++) {
		if(is_prime[i-s]) cout << i << endl;
	}
	cout << endl;
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
}f