#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,a;
    cin >> n >> a;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    vector<vector<ll>> dp(n+1,vector<ll> (3030));
    dp[0][0]=1;
    for(int k=0;k<n;k++) {
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<3030;j++) {
                if(dp[i][j]==0) continue;
                if(j+x[k]<3030) dp[i+1][j+x[k]]+=dp[i][j];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=dp[i][i*a];
    cout << ans << endl; 
    return 0;
}