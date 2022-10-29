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

ll modinv(ll a) {
    return modpow(a,mod-2);
}

int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(n+1,vector<ll> (k+1,0));
    dp[0][0]=1;
    for(ll l=0;l<k;l++) {
        for(ll i=0;i<n;i++) {
            for(ll j=1;j<=m;j++) { 
                if(i+j>n) {
                    dp[n-(i+j-n)][l+1]+=dp[i][l];
                    dp[n-(i+j-n)][l+1]%=mod;
                } else {
                    dp[i+j][l+1]+=dp[i][l];
                    dp[i+j][l+1]%=mod;
                }
            }
        }
    }
    ll tot=0;
    rep(i,k+1) {
        ll p=dp[n][i]*modinv(modpow(m,i))%mod;
        tot=(tot+p)%mod; 
    }
    cout << tot << endl;
    return 0;
}