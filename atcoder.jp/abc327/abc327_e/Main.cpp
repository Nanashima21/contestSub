#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<double> n9(1,1.0);
    rep(i,n) n9.push_back(n9.back()*0.9);  
    vector<vector<double>> dp(n+1,vector<double> (n+2,0));
    for(int k=n-1;k>=0;k--) {
        int i=n-k;
        for(int j=0;j<=i;j++) {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+n9[j]*p[k]);
        }
    }
    double tot=0.0;
    double ans=-INF;
    for(int i=1;i<=n;i++) {
        tot+=n9[i-1];
        ans=max(ans,dp[n][i]/tot-1200.0/sqrt(i));
    }
    printf("%.10f\n",ans);
    return 0;
}