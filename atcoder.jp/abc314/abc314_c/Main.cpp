#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll m,n; string s;
    cin >> n >> m >> s;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<int>> v(m,vector<int> ());
    rep(i,n) v[c[i]-1].push_back(i);
    rep(i,m) {
        char c=s[v[i].back()];
        rep(j,(int)v[i].size()) {
            char nc=s[v[i][j]];
            s[v[i][j]]=c;
            c=nc;
        }
    }
    cout << s << endl;
    return 0;
}