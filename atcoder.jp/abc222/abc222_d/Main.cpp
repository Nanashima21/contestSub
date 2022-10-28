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
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<vector<ll>> dp(n,vector<ll> (3030));
    for(int i=a[0];i<=b[0];i++) dp[0][i]++;
    for(int i=0;i<n-1;i++) {
        for(int j=a[i];j<=b[i];j++) {
            dp[i+1][max(1LL*j,a[i+1])]+=dp[i][j];
            dp[i+1][j]%=mod;
        }
        for(int j=0;j<=3000;j++) {
            if(a[i+1]<=j&&j<=b[i+1]) {
                if(j==0) continue;
                dp[i+1][j]+=dp[i+1][j-1];
                dp[i+1][j]%=mod;
            } else dp[i+1][j]=0;
        }
    }
    ll ans=0;
    for(int i=a[n-1];i<=b[n-1];i++) ans=(ans+dp[n-1][i])%mod;
    cout << ans << endl;
    return 0;
}