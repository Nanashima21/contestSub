#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

ll modpow(ll n,ll r,ll m) {
    ll num=1;
    n%=m;
    while(r) {
        if(r&1) num=num*n%m;
        n=n*n%m;
        r/=2;
    }
    return num;
}

int main() {
    ll n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>> (n+1,vector<ll> (2,0)));
    rep(i,n) rep(j,2) {
        dp[n][i][j]=1;
        dp[i][n][j]=0;
    }
    for(int i=n-1;i>=0;i--) {
        for(int j=n-1;j>=0;j--) {
            for(int k=1;k<=p;k++) {
                dp[i][j][0]+=dp[min(n,(ll)i+k)][j][1];
                dp[i][j][0]%=mod;
            }
            dp[i][j][0]*=modpow(p,mod-2,mod);
            dp[i][j][0]%=mod;
            for(int k=1;k<=q;k++) {
                dp[i][j][1]+=dp[i][min(n,(ll)j+k)][0];
                dp[i][j][1]%=mod;
            }
            dp[i][j][1]*=modpow(q,mod-2,mod);
            dp[i][j][1]%=mod;
        }
    }
    cout << dp[a][b][0] << endl;
    return 0;
}