#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=1000000007;

ll modpow(ll n,ll r) {
    ll num=1;
    while(r) {
        if(r&1) num=num*n%mod;
        n=n*n%mod;
        r/=2;
    }
    return num;
}

vector<ll> shi;
ll bo=1;

ll comb(ll n,ll r) {
    //ll x=1,y=1;
    //for(ll i=0;i<r;i++) x=x*(n-i)%mod;
    //for(ll i=1;i<=r;i++) y=y*i%mod;
    return shi[n]*modpow(bo,mod-2)%mod;
}

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),b(n);
    rep(i,n) {
        cin >> a[i];
        b[i]=-a[i];
    }  
    shi.resize(n,1);
    for(ll i=0;i<k-1;i++) shi[n-1]=shi[n-1]*(n-1-i)%mod;
    for(ll i=n-2;i>=1;i--) shi[i]=((shi[i+1]*modpow(i+1,mod-2)%mod)*(i+2-k))%mod;
    for(ll i=1;i<k;i++) bo=bo*i%mod;
    vector<ll> cb;
    for(int i=n-1;;i--) {
        if(i<k-1) break;
        cb.push_back(comb(i,k-1));
    }
    sort(all(a));
    sort(all(b));
    ll ans=0;
    for(int i=0;i<n;i++) {
        ll m=n-i-1;
        if(m<k-1) break;
        ans=(ans+((-a[i]*cb[i])%mod+mod)%mod)%mod;
        ans=(ans+mod)%mod;
    }
    for(int i=0;i<n;i++) {
        ll m=n-i-1;
        if(m<k-1) break;
        ans=(ans+((-b[i]*cb[i])%mod+mod)%mod)%mod;
        ans=(ans+mod)%mod;
    }
    cout << ans << endl;
    return 0;
}