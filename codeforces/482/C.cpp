#include <bits/stdc++.h>

#define rep0(i, n)  for(int i=0; i<n; i++)
#define rep1(i, n)  for(int i=1; i<=n; i++)

#define fup(i, a, b)  for(int i=a; i<=b; i++)
#define fdown(i, a, b)  for(int i=a; i>=b; i++)

#define _1 first
#define _2 second

#define hashmap unordered_map
#define hashset unordered_set

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<ll> vll;

vi P;
vi N;
vvi G;

int node_count(int p, int u) {
    int nodes = 1;
    for(auto v: G[u]) {
        if(v != p) {
            nodes += node_count(u, v);
        }
    }
    return nodes;
}

bool find_path(int p, int u, int dest) {
    // cout << u << ": " << endl;
    if(u == dest) {
        return true;
    } else {
        for(auto v: G[u]) {
            if(v == p) continue;
            // cout << v << " ";
            bool found = find_path(u, v, dest);
            if(found) {
                P[v] = u;
                N[u] = v;
                return true;
            }
        }
        return false;
    }
}

int run() {
    int n, x, y, u, v;
    cin >> n >> x >> y;
    --x; --y;
    
    G.resize(n, vi());
    P.resize(n, -1);
    N.resize(n, -1);

    
    rep0(i, n-1) {
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    find_path(-1, x, y);

    int px = N[x];
    int py = P[y];

    // cout << "x: " << px << " " << x << endl;
    // cout << "y: " << py << " " << y << endl;

    // int k = x;
    // while(k != y) {
    //     cout << k + 1 << " ";
    //     k = N[k];
    // }
    // cout << y + 1 << endl;

    // k = y;
    // while(k != x) {
    //     cout << k + 1 << " ";
    //     k = P[k];
    // }
    // cout << x + 1 << endl;

    ll nx = node_count(px, x);
    ll ny = node_count(py, y);

    // cout << "nx: " << nx << endl;
    // cout << "ny: " << ny << endl;

    ll long_n = n;

    cout << long_n * (long_n - 1) - (nx * ny) << endl;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  run();
  return 0;
}
