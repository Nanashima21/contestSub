#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k,p;
    cin >> n >> k >> p;
    vector<ll> c(n);
    vector<vector<ll>> a(n,vector<ll> (k));
    rep(i,n) {
        cin >> c[i];
        rep(j,k) cin >> a[i][j];
    }
    ll m=10;
    rep(i,k-1) m*=10;
    vector<vector<ll>> dp(n+1,vector<ll> (m,INF));
    dp[0][0]=0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            if(dp[i-1][j]==INF) continue;
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            string str=to_string(j);
            int x=k-(int)str.size();
            reverse(all(str));
            rep(l,x) str+='0';
            string y;
            rep(l,k) y+=to_string(min(p,str[l]-'0'+a[i-1][l]));
            reverse(all(y));
            dp[i][stoll(y)]=min(dp[i][stoll(y)],dp[i-1][j]+c[i-1]);
            //cout << str << " " << y << " " << dp[i][stoll(y)] << endl;
        }
    }
    string str;
    rep(i,k) str+=to_string(p);
    if(dp[n][stoll(str)]==INF) cout << -1 << endl;
    else cout << dp[n][stoll(str)] << endl;
    return 0;
}