#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,l;
    cin >> n >> m >> l;
    vector<pl> a,b;
    rep(i,n) {
        ll x;
        cin >> x;
        a.push_back({x,i});
    }
    rep(i,m) {
        ll y;
        cin >> y;
        b.push_back({y,i});
    }
    sort(rall(a));
    sort(rall(b));
    set<pair<int,int>> sep;
    rep(i,l) {
        int c,d;
        cin >> c >> d;
        sep.insert({c-1,d-1});
    }
    ll ans=0;
    rep(i,n) {
        if(a[i].first+b[0].first<ans) break;
        int idx=0;
        while(true) {
            if(idx==n) break;
            if(sep.find({a[i].second,b[idx].second})!=sep.end()) {
                idx++;
                continue;
            }
            ans=max(ans,a[i].first+b[idx].first);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}