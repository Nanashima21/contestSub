#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<ll>> dp(60,vector<ll> (n));
    rep(i,n) dp[0][i]=a[i];
    rep(i,59) for(int j=0;j<n;j++) dp[i+1][j]=dp[i][dp[i][j]];
    ll ans=0;
    rep(i,60) {
        if(k&1) ans=dp[i][ans];
        k=k>>1;
    }
    cout << ans+1 << endl;
    return 0;
}