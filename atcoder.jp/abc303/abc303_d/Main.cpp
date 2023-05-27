#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll x,y,z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    ll n=(ll)s.size();
    vector<vector<ll> > dp(n+1,vector<ll> (2,INF));
    dp[0][0]=0;
    dp[0][1]=z;
    for(int i=1;i<=n;i++) {
        if(s[i-1]=='a') {
            dp[i][0]=min(dp[i][0],dp[i-1][0]+x);
            dp[i][0]=min(dp[i][0],dp[i-1][1]+y+z);
            dp[i][1]=min(dp[i][1],dp[i-1][0]+x+z);
            dp[i][1]=min(dp[i][1],dp[i-1][1]+y);
        } else {
            dp[i][0]=min(dp[i][0],dp[i-1][0]+y);
            dp[i][0]=min(dp[i][0],dp[i-1][1]+x+z);
            dp[i][1]=min(dp[i][1],dp[i-1][0]+y+z);
            dp[i][1]=min(dp[i][1],dp[i-1][1]+x);
        }
    }
    cout << min(dp[n][0],dp[n][1]) << endl;
    return 0;
}