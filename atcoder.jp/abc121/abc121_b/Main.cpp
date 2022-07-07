#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    vector<vector<int>> a(n,vector<int> (m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    int ans=0;
    rep(i,n) {
        ll tot=0;
        rep(j,m) tot+=a[i][j]*b[j];
        tot+=c;
        if(tot>0) ans++;
    }
    cout << ans << endl;
    return 0;
}