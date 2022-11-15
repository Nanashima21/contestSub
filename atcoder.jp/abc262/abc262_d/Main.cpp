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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans=0;
    for(int i=1;i<=n;i++) {
        vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>> (i+1,vector<ll> (i,0)));
        dp[0][0][0]++;
        for(int j=0;j<n;j++) {
            for(int k=0;k<=i;k++) {
                for(int l=0;l<i;l++) {
                    dp[j+1][k][l]=(dp[j+1][k][l]+dp[j][k][l])%mod;
                    if(k!=i) dp[j+1][k+1][(l+a[j])%i]=(dp[j+1][k+1][(l+a[j])%i]+dp[j][k][l])%mod;
                }
            }
        }
        ans+=dp[n][i][0];
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}