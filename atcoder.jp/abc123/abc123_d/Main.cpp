#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x),b(y),c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    vector<ll> d;
    rep(i,x) rep(j,y) d.push_back(a[i]+b[j]);
    sort(rall(d));
    vector<ll> e;
    rep(i,min(k,x*y)) rep(j,z) e.push_back(d[i]+c[j]);
    sort(rall(e));
    for(int i=0;i<k;i++) cout << e[i] << endl;
    return 0;
}