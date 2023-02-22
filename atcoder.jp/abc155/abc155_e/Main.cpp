#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    reverse(all(s));
    int n=(int)s.size();
    vector<vector<ll>> dp(n+1,vector<ll> (2,INF));
    dp[0][0]=0;
    rep(i,n) rep(d,2) {
        if(dp[i][d]==INF) continue;
        int c=s[i]-'0';
        if(c==9&&d) dp[i+1][1]=min(dp[i+1][1],dp[i][1]);
        else {
            if(d) c++;
            dp[i+1][0]=min(dp[i+1][0],dp[i][d]+c);
            dp[i+1][1]=min(dp[i+1][1],dp[i][d]+10-c);
        }
    }
    cout << min(dp[n][0],dp[n][1]+1) << endl;
    return 0; 
}