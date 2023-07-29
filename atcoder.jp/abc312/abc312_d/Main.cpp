#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

int main() {
    string s;
    cin >> s;
    int n=(int)s.size();
    vector<vector<ll>> dp(n,vector<ll> (3030,0));
    if(s[0]=='(') dp[0][1]=1;
    else if(s[0]=='?') dp[0][1]=1;
    for(int i=1;i<n;i++) {
        rep(j,3030) {
            if(s[i]==')'&&j>0) dp[i][j-1]=(dp[i][j-1]+dp[i-1][j])%mod;
            if(s[i]=='(') dp[i][j+1]=(dp[i][j+1]+dp[i-1][j])%mod;
            if(s[i]=='?') {
                dp[i][j+1]=(dp[i][j+1]+dp[i-1][j])%mod;
                if(j>0) dp[i][j-1]=(dp[i][j-1]+dp[i-1][j])%mod;
            }
        }
    }
    cout << dp[n-1][0] << endl;
    return 0;
}