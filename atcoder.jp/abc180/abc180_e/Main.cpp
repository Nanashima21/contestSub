#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n),b(n),c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    vector<vector<ll>> dp(1<<n,vector<ll> (n,INF));
    for(int i=0;i<n;i++) dp[1<<i][i]=abs(a[0]-a[i])+abs(b[0]-b[i])+max(0LL,c[i]-c[0]);
    for(int bit=1;bit<(1<<n);bit++) {
        rep(i,n) if(bit>>i&1) {
            rep(j,n) {
                if(i==j) continue;
                dp[1<<j|bit][j]=min(dp[1<<j|bit][j],dp[bit][i]+abs(a[i]-a[j])+abs(b[i]-b[j])+max(0LL,c[j]-c[i]));
            }
        }
    }
    ll ans=INF;
    for(int i=0;i<n;i++) ans=min(ans,dp[(1<<n)-1][i]+abs(a[0]-a[i])+abs(b[0]-b[i])+max(0LL,c[0]-c[i]));
    cout << ans << endl;
    return 0;
}