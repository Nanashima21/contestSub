#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m),s(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        rep(j,b[i]) {
            ll c;
            cin >> c;
            c--;
            s[i]|=1<<c;
        }
    }
    vector<vector<ll>> dp(m+1,vector<ll> (1<<n,INF));
    dp[0][0]=0;
    rep(i,m) {
        for(int bit=0;bit<(1<<n);bit++) {
            dp[i+1][bit]=min(dp[i+1][bit],dp[i][bit]);
            dp[i+1][bit|s[i]]=min(dp[i+1][bit|s[i]],dp[i][bit]+a[i]);
        }
    }
    ll ans=dp[m][(1<<n)-1];
    if(ans==INF) ans=-1;
    cout << ans << endl;
    return 0;
}