#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m,r;
    cin >> n >> m >> r;
    vector<int> v(r);
    rep(i,r) {
        cin >> v[i];
        v[i]--;
    }
    sort(all(v));
    vector<vector<ll>> dp(n,vector<ll> (n,INF));
    rep(i,m) {
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b]=c;
        dp[b][a]=c;
    }
    rep(k,n) rep(i,n) rep(j,n) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    ll ans=INF;
    do {
        ll tot=0;
        for(int i=1;i<r;i++) tot+=dp[v[i-1]][v[i]];
        ans=min(ans,tot);
    } while(next_permutation(all(v)));
    cout << ans << endl;
    return 0;
}