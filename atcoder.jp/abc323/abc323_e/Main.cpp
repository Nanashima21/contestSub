#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

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
    ll n,x;
    cin >> n >> x;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    vector<ll> dp(x+1,0);
    dp[0]=1;
    ll ans=0;
    if(t[0]>x) ans=modpow(n,mod-2,mod);
    for(int i=1;i<=x;i++) {
        rep(j,n) if(i-t[j]>=0) {
            dp[i]+=dp[i-t[j]];
            dp[i]%=mod;
        }
        dp[i]=(dp[i]*modpow(n,mod-2,mod))%mod;
        if(t[0]+i>x) {
            ans+=(dp[i]*modpow(n,mod-2,mod))%mod;
            ans%=mod;
        }
    }
    cout << ans << endl;
    return 0;
}