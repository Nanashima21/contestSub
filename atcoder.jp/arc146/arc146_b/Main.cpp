#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll f(ll x,ll y) {
    for(int i=31;i>=0;i--) {
        if((y>>i)&1) continue;
        ll z=y|((1LL<<i)-1);
        if(z<x) y^=(1LL<<i);
    }
    return y;
}

int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll tot=0;
    for(int i=31;i>=0;i--) {
        vector<ll> b(n);
        rep(j,n) b[j]=f(a[j],tot+(1LL<<i))-a[j];
        sort(all(b));
        ll sum=0;
        rep(j,k) sum+=b[j];
        if(sum<=m) tot+=(1LL<<i);
    } 
    cout << tot << endl;
    return 0;
}