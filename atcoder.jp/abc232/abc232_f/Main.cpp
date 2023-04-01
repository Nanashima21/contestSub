#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<ll> dp(1<<n,INF);
    dp[0]=0;
    for(int bit=0;bit<(1<<n);bit++) {
        int idx=__builtin_popcount(bit);
        rep(i,n) {
            if(bit>>i&1) continue;
            int cnt=__builtin_popcount((~bit)&((1<<i)-1));
            dp[bit^(1<<i)]=min(dp[bit^(1<<i)],dp[bit]+llabs(a[i]-b[idx])*x+cnt*y);
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}