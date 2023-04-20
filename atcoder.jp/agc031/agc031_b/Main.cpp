#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> c(n+1);
    rep(i,n) cin >> c[i+1];
    vector<ll> dp(n+2),tot(200200);
    dp[0]=1;
    tot[c[1]]=1;
    for(int i=1;i<=n;i++) {
        dp[i]=tot[c[i]];
        if(c[i]!=c[i+1]) {
            tot[c[i+1]]+=dp[i];
            tot[c[i+1]]%=mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}