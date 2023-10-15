#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod = 998244353;

vector<pair<ll,ll>> prime_factorize(ll n) {
    vector<pair<ll,ll>> res;
    for (ll a=2;a*a<=n;++a) {
        if (n%a!=0) continue;
        ll ex=0;
        while(n%a==0) {
            ++ex;
            n/=a;
        }
        res.push_back({a,ex});
    }
    if (n!=1) res.push_back({n,1LL});
    return res;
    //const auto &res=prime_factorize(n);
}

ll modpow(ll n,ll r,ll m) {
    ll num=1;
    n%=m;
    while(r) {
        if(r&1) num=num*n%m;
        n=n*n%m;
        r/=2;
    }
    return num;
}

int main() {
    ll a,b;
    cin >> a >> b;
    const auto &resp=prime_factorize(a);
    bool flag=true;
    ll ans=1;
    for(auto u:resp) {
        if(u.second%2==1) flag=false;  
        ans*=(b%mod*u.second%mod+1LL)%mod;
        ans%=mod;
    }
    ans=b%mod*ans%mod;
    if(flag&&b%2==1) ans=(ans-1+mod)%mod;
    cout << ans*modpow(2,mod-2,mod)%mod << endl;
    return 0;
}