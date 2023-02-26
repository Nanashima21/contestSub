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
    rep(i,n) cin >> a[i] >> b[i];
    if(n==1) {
        cout << 2 << endl;
        return 0;
    }
    vector<vector<ll>> dp(n,vector<ll> (2,0));
    if(a[0]!=a[1]) dp[1][0]++;
    if(b[0]!=a[1]) dp[1][0]++;
    if(a[0]!=b[1]) dp[1][1]++;
    if(b[0]!=b[1]) dp[1][1]++;
    for(int i=2;i<n;i++) {
        if(a[i-1]!=a[i]) dp[i][0]=(dp[i][0]+dp[i-1][0])%mod;;
        if(b[i-1]!=a[i]) dp[i][0]=(dp[i][0]+dp[i-1][1])%mod;;
        if(a[i-1]!=b[i]) dp[i][1]=(dp[i][1]+dp[i-1][0])%mod;;
        if(b[i-1]!=b[i]) dp[i][1]=(dp[i][1]+dp[i-1][1])%mod;;
    }
    cout << (dp[n-1][0]+dp[n-1][1])%mod << endl;
    return 0;
}