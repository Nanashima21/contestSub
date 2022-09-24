#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> dp(n+1);
    rep(i,n+1) {
        rep(j,k) {
            if(a[j]>i) break;
            dp[i]=max(dp[i],i-dp[i-a[j]]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}