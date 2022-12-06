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

ll prob(ll p,ll r) {
    return modpow(p,r)*modpow(modpow(100,r),mod-2)%mod;
}

int main() {
    ll n; int p;
    cin >> n >> p;
    vector<ll> p100(n+1,1);
    rep(i,n) p100[i+1]=(p100[i]*100)%mod;
    vector<ll> fact(n+1);
    fact[0]=1;
    for (int i=1;i<=n;i++) fact[i]=(fact[i-1]*i)%mod;
    const auto comb = [&fact](int n, int r) {
        return ((fact[n]*modpow(fact[r],mod-2))%mod*modpow(fact[n-r],mod-2))%mod;
    };
    ll ans=0;
    for(int i=n;i>=0;i--) {
        ll num=((n-i)+1)/2;
        if(num*2+i<=n) ans+=(((num+i)*comb(num+i,num))%mod*prob(100-p,i))%mod*prob(p,num)%mod;
        else ans+=(((((num+i)*comb(num+i-1,num-1))%mod*prob(100-p,i))%mod*prob(p,num-1))%mod)*prob(p,1)%mod;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}