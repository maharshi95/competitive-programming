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
typedef vector<ll> vll;

int max_count(string & s) {
    map<char, int> mp;
    for(auto ch: s) {
        ++mp[ch];
    }
    int m_cnt = 0;
    for(char ch ='a'; ch <= 'z'; ++ch) {
        m_cnt = max(m_cnt, mp[ch]);
    }
    for(char ch ='A'; ch <= 'Z'; ++ch) {
        m_cnt = max(m_cnt, mp[ch]);
    }
    return m_cnt;
}

int run() {
    ll N;
    cin >> N;
    string S[3];
    ll M[3];
    ll FL[3];
    ll L;
    
    rep0(i, 3) {
        cin >> S[i];
        L = S[i].size();
        M[i] = max_count(S[i]);
        // cout << M[i] << " ";
    }

    rep0(i, 3) {
        if(L == M[i]) {
            if(N != 1) {
                FL[i] = L;
            } else {
                FL[i] = L - 1;
            }
        } else if(M[i] == L -1 ) {
            if(N == 0) {
                FL[i] = L - 1;
            } else {
                FL[i] = L;
            }
        }
        else {
            FL[i] = min(L, M[i] + N);
        }
    }

    // cout << M[0] << " " << M[1] << " " << M[2] << endl;
    // cout << FL[0] << " " << FL[1] << " " << FL[2] << endl;

    if(FL[0] > max(FL[1], FL[2])) {
        cout << "Kuro" << endl;
    }
    else if(FL[1] > max(FL[0], FL[2])) {
        cout << "Shiro" << endl;
    }
    else if(FL[2] > max(FL[0], FL[1])) {
        cout << "Katie" << endl;
    }
    else {
        cout << "Draw" << endl;
    }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  run();
  return 0;
}
