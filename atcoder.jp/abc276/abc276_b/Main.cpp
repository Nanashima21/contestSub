#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> v(n,vector<ll> ());
    rep(i,m) {
        ll a,b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    rep(i,n) {
        sort(all(v[i]));
        cout << (int)v[i].size();
        rep(j,(int)v[i].size()) {
            cout << " ";
            cout << v[i][j]+1;
        } cout << endl;
    }
    return 0;
}