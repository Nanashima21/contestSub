#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

ll modpow(ll n,ll r) {
    ll num=1;
    while(r) {
        if(r&1) num=num*n%mod;
        n=n*n%mod;
        r/=2;
    }
    return num;
}

ll comb(ll n,ll r) {
    ll x=1,y=1;
    for(ll i=0;i<r;i++) x=x*(n-i)%mod;
    for(ll i=1;i<=r;i++) y=y*i%mod;
    return x*modpow(y,mod-2)%mod;
}

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    ll tot=0;
    rep(i,n) {
        cin >> a[i];
        if(i) tot+=a[i];
    }
    ll ans=1;
    if(a[0]>=tot+k) {
        for(int i=1;i<n;i++) {
            ans*=comb(a[i]+k-1,k-1);
            ans%=mod;
        }
        if(a[0]-tot-1>0) ans*=comb(a[0]-tot-1,k-1);
        ans%=mod;
    } else ans=0;
    cout << ans << endl;
    return 0;
}