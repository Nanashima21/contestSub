#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q;
    cin >> n >> q;
    vector<ll> par(2,-1),child(n+1);
    rep(i,n-1) {
        int a;
        cin >> a;
        par.push_back(a);
    }
    for(int i=2;i<n+1;i++) child[par[i]]++;
    while(q--) {
        int m;
        cin >> m;
        vector<int> v(m);
        rep(j,m) cin >> v[j];
        ll ans=0;
        rep(j,m) {
            ans+=child[v[j]];
            if(par[v[j]]!=-1&&binary_search(all(v),par[v[j]])) ans--;
            else ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}