#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n; ll x;
    cin >> n >> x;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<vector<bool>> dp(n+1,vector<bool> (10010,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<10010;j++) {
            for(ll k=1;k<=b[i-1];k++) {
                if(dp[i-1][j]) {
                    dp[i][j]=true;
                    if(j+a[i-1]*k<10010) dp[i][j+a[i-1]*k]=true;
                }
            }
        }
    }
    cout << (dp[n][x] ? "Yes" : "No") << endl;
    return 0;
}