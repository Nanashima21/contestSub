#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> g(n,vector<ll> (n,0));
    rep(i,n-1) {
        rep(j,n-i-1) {
            ll d;
            cin >> d;
            g[i][i+j+1]=d;
            g[i+j+1][i]=d;
        }
    }

    ll ans=0;
    vector<ll> dp(1<<n,0);
    for(int bit=0;bit<(1<<n);bit++) {
        vector<int> v;
        rep(i,n) if(bit>>i&1) v.push_back(i);
        int m=(int)v.size();
        if(m%2==1) continue;
        if(m==2) dp[bit]=g[v[0]][v[1]];
        else {
            rep(i,m) rep(j,m) {
                if(i==j) continue;
                int nbit=bit;
                nbit^=1<<v[i];
                nbit^=1<<v[j];
                dp[bit]=max(dp[bit],dp[nbit]+g[v[i]][v[j]]);
            }
        }
    }
    
    rep(i,1<<n) ans=max(ans,dp[i]);
    cout << ans << endl;

    return 0; 
}