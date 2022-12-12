#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,k,d;
    cin >> n >> k >> d;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>> (k+1,vector<ll> (d,-1)));
    dp[0][1][a[0]%d]=a[0];
    for(int i=1;i<n;i++) {
        dp[i][1][a[i]%d]=max(dp[i][1][a[i]%d],a[i]);
        for(int j=0;j<k;j++) {
            for(int l=0;l<d;l++) {
                if(dp[i-1][j][l]==-1) continue;
                dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]);
                dp[i][j+1][(a[i]+dp[i-1][j][l])%d]=max(dp[i][j+1][(a[i]+dp[i-1][j][l])%d],a[i]+dp[i-1][j][l]);
                
            }
        }
    }
    ll ma=-1;
    rep(i,n) ma=max(ma,dp[i][k][0]);
    cout << ma << endl; 
    return 0;
}