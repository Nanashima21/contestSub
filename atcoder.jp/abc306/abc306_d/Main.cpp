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
    vector<ll> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<vector<ll>> dp(n+1,vector<ll> (2,-INF));
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<=n;i++) {
        if(x[i-1]==0) {
            dp[i][0]=max(dp[i-1][0],dp[i-1][0]+y[i-1]);
            dp[i][0]=max(dp[i][0],dp[i-1][1]+y[i-1]);
            dp[i][1]=dp[i-1][1];
        } else {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+y[i-1]);
        }
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
    return 0;
}