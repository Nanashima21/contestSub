#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<ll> s(n-1),x(m);
    rep(i,n-1) cin >> s[i];
    rep(i,m) cin >> x[i];
    ll a=0,b=1;
    map<ll,ll> mp;
    rep(i,n) {
        rep(j,m) mp[(x[j]-a)*b]++;
        if(i<n-1) {
            a=s[i]-a;
            b*=-1;
        }
    }
    ll ans=0;
    for(auto u:mp) ans=max(ans,u.second);
    cout << ans << endl;
    return 0;
}