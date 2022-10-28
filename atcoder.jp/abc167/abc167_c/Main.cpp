#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,x;
    cin >> n >> m >> x;
    vector<ll> c(n);
    vector<vector<ll>> a(n,vector<ll> (m));
    rep(i,n) {
        cin >> c[i];
        rep(j,m) cin >> a[i][j];
    }
    ll mi=INF;
    for(int bit=0;bit<(1<<n);bit++) {
        ll tot=0;
        vector<ll> y(m);
        rep(i,n) if(1<<i&bit) {
            tot+=c[i];
            rep(j,m) y[j]+=a[i][j];
        }
        bool flag=true;
        rep(i,m) if(y[i]<x) flag=false;
        if(flag) mi=min(mi,tot);
    }
    if(mi==INF) mi=-1;
    cout << mi << endl;
    return 0;
}