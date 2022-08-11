#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,x;
    cin >> n >> x;
    vector<pl> p;
    ll ans=INF;
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        p.push_back({a,b});
    }
    ll tot=0;
    for(int i=0;i<n;i++) {
        tot+=p[i].first+p[i].second;
        ans=min(ans,tot+max(0LL,(x-i-1)*p[i].second));
    }
    cout << ans << endl;
    return 0;
}