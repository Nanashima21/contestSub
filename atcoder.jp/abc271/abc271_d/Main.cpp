#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,s;
    cin >> n >> s;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<vector<int>> dp(n+1,vector<int> (s+1,-1));
    dp[0][0]=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=s;j++) {
            if(dp[i][j]!=-1) {
                if(j+a[i]<=s) dp[i+1][j+a[i]]=j;
                if(j+b[i]<=s) dp[i+1][j+b[i]]=j;
            }
        }
    }
    if(dp[n][s]!=-1) {
        cout << "Yes" << endl;
        int idx=dp[n][s],j=1;
        string ans;
        if(s-idx==a[n-j]) ans+='H';
        else ans+='T';
        while(idx!=0) {
            j++;
            if(n<j) break;
            if(idx-dp[n-j+1][idx]==a[n-j]) ans+='H';
            else ans+='T';
            idx=dp[n-j+1][idx];
        }
        reverse(all(ans));
        cout << ans << endl;
    } else cout << "No" << endl;
    return 0;
}