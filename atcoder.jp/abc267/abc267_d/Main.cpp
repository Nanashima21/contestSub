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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> dp(n,vector<ll> (m,-INF));
    dp[0][0]=a[0];
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j!=0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]*(j+1));
            else dp[i][j]=max(dp[i][j],a[i]);
        }
    }
    ll ma=-INF;
    rep(i,n) ma=max(ma,dp[n-1][m-1]);
    cout << ma << endl; 
    return 0;
}