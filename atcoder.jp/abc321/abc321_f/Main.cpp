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
    ll q,k;
    cin >> q >> k;
    vector<ll> dp(k+1,0);
    dp[0]=1;
    while(q--) {
        string s; ll x;
        cin >> s >> x;
        if(s=="+") {
            for(int i=k;i>=0;i--) {
                if(i+x<=k) dp[i+x]=(dp[i+x]+dp[i])%mod;
            }
        } else {
            for(int i=x;i<=k;i++) {
                dp[i]=(dp[i]-dp[i-x]+mod)%mod;
            }
        }
        cout << dp[k] << "\n";
    }
    return 0;
}