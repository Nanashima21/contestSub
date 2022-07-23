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
    vector<ll> x(n),c(m),y(m);
    map<ll,ll> mp;
    rep(i,n) cin >> x[i];
    rep(i,m) {
        cin >> c[i] >> y[i];
        mp[c[i]]=y[i];
    }
    vector<vector<ll>> dp(n,vector<ll> (n+1,0));
    dp[0][1]=x[0]+mp[1];
    for(int i=1;i<n;i++) {
        rep(j,n) dp[i][0]=max(dp[i][0],dp[i-1][j]); 
        for(int j=1;j<=i+1;j++) {
            dp[i][j]=max(dp[i][j],dp[i-1][j-1])+x[i]+mp[j];
        }
    }
    ll ma=0;
    rep(i,n+1) ma=max(ma,dp[n-1][i]);
    cout << ma << endl;
    return 0;
}