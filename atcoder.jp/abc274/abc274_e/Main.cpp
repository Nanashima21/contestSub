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
    vector<ll> x(n+m),y(n+m);
    rep(i,n+m) cin >> x[i] >> y[i];
    vector<vector<double>> dp(n+m,vector<double> (1<<(n+m),INF));
    rep(i,n+m) dp[i][1<<i]=hypot(x[i],y[i]);
    for(int bit=1;bit<(1<<(n+m));bit++) {
        int cnt=0;
        for(int i=n;i<n+m;i++) if(bit&1<<i) cnt++;
        rep(i,n+m) if(bit&1<<i) {
            rep(j,n+m) if(!(bit&1<<j)) {
                dp[j][bit|1<<j]=min(dp[j][bit|1<<j],dp[i][bit]+hypot(x[i]-x[j],y[i]-y[j])*pow(0.5,cnt));
            }
        }
    }
    double ans=INF;
    rep(i,n) for(int bit=(1<<n)-1;bit<(1<<(n+m));bit+=1<<n) {
        int cnt=0;
        for(int j=n;j<n+m;j++) if(bit&1<<j) cnt++;
        ans=min(ans,dp[i][bit]+hypot(x[i],y[i])*pow(0.5,cnt));
    }
    printf("%.10f\n",ans);
    return 0;
}