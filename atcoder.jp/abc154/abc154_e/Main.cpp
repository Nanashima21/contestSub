#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s; int k;
    cin >> s >> k;
    int n=(int)s.size();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>> (5,vector<ll> (2,0)));
    dp[0][0][0]=1;
    dp[0][1][0]=s[0]-'1';
    dp[0][1][1]=1;
    for(int i=1;i<n;i++) {
        rep(j,k+1) {
            dp[i][j][0]+=dp[i-1][j][0];
            ll x=s[i]-'0';
            dp[i][j+1][0]+=dp[i-1][j][0]*9;
            if(x!=0) {
                dp[i][j+1][0]+=dp[i-1][j][1]*(x-1);
                dp[i][j][0]+=dp[i-1][j][1];
            }
            if(s[i]=='0') dp[i][j][1]+=dp[i-1][j][1];
            else dp[i][j+1][1]+=dp[i-1][j][1];
        }
    }
    cout << dp[n-1][k][0]+dp[n-1][k][1] << endl;
    return 0;
}