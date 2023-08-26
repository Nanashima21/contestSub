#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n),y(n),z(n);
    ll totz=0;
    rep(i,n) {
        cin >> x[i] >> y[i] >> z[i];
        totz+=z[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll> (200200,INF));
    dp[0][0]=0;
    for(int i=1;i<=n;i++) {
        rep(j,100100) {
            if(dp[i-1][j]==INF) continue;
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            dp[i][j+z[i-1]]=min(dp[i][j+z[i-1]],dp[i-1][j]+max(0LL,(x[i-1]+y[i-1]+1)/2-x[i-1]));
        }
    }
    ll ans=INF;
    for(int i=totz/2+1;i<200200;i++) ans=min(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}