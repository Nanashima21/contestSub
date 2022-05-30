#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

int main() {
    ll n,m;
    cin >> n >> m;
    if(n>60) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<ll>> dp(60,vector<ll> (62,0));
    vector<ll> p2(62,0);
    for(int i=1;i<62;i++) {
        if(i==1) p2[i]=1;
        else p2[i]=p2[i-1]*2;
        if(m<p2[i]) {
            dp[0][i]=m;
            p2[i]=m;
            break;
        } else {
            dp[0][i]=p2[i];
            m-=p2[i];
        }
    }
    for(int i=1;i<62;i++) dp[0][i]%=mod;
    for(int i=1;i<60;i++) {
        for(int j=1;j<62;j++) {
            for(int k=j+1;k<62;k++) {
                dp[i][k]=(dp[i][k]+(dp[i-1][j]*dp[0][k])%mod)%mod;
            }
        }
    }
    ll ans=0;
    rep(i,62) ans=(ans+dp[n-1][i])%mod;
    cout << ans << endl;
    return 0;
}