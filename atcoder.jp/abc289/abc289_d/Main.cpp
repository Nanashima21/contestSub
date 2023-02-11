#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll m;
    cin >> m;
    vector<ll> b(m);
    rep(i,m) cin >> b[i];
    ll x;
    cin >> x;
    vector<bool> dp(x+1,false);
    dp[0]=true;
    for(int i=0;i<x;i++) {
        if(!dp[i]) continue;
        if(binary_search(all(b),i)) continue;
        for(int j=0;j<n;j++) {
            if(a[j]+i<=x) dp[a[j]+i]=true;
        }
    }
    cout << (dp[x] ? "Yes" : "No") << endl;
    return 0;
}