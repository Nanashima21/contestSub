#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll h,n;
    cin >> h >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<vector<ll>> dp(n,vector<ll> (h+1,INF));
    int idx=0;
    while(true) {
        dp[0][min(a[0]*idx,h)]=b[0]*idx;
        if(a[0]*idx>=h) break;
        idx++;
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<h+1;j++) {
            if(dp[i-1][j]!=INF) dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if(dp[i][j]!=INF) {
                dp[i][min(j+a[i],h)]=min(dp[i][min(j+a[i],h)],dp[i][j]+b[i]);
            }
        }
    }
    ll mi=INF;
    rep(i,n) mi=min(mi,dp[i][h]);
    cout << mi << endl;
    return 0;
}