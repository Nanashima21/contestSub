#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> t(n),x(n),a(n);
    set<pl> se;
    map<pl,ll> mp;
    rep(i,n) {
        cin >> t[i] >> x[i] >> a[i];
        se.insert({t[i],x[i]});
        mp[{t[i],x[i]}]=a[i];
    }
    ll m=t.back();
    vector<vector<ll>> dp(m+1,vector<ll> (5));
    if(se.find({0,0})!=se.end()) dp[0][0]=mp[{0,0}]; 
    for(int i=1;i<=m;i++) {
        rep(j,5) {
            if(i<j) continue;
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j>0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            if(j<4) dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
            if(se.find({i,j})!=se.end()) dp[i][j]+=mp[{i,j}];
        }
    }
    ll ma=0;
    rep(i,5) ma=max(ma,dp[m][i]);
    cout << ma << endl; 
    return 0;
}