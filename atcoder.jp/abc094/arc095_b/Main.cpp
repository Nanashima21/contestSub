#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    ll ma=0;
    pl ans;
    rep(i,n) {
        int it=lower_bound(all(a),a[i]/2)-a.begin();
        if(a[i]<a[it]) continue;
        ll tot=0;
        if(it!=0) {
            tot=min(a[i]-a[it-1],a[it-1])+a[i];
            if(ma<tot) {
                ma=tot;
                ans={a[i],a[it-1]};
            }
        }
        if(a[i]==a[it]) continue;
        tot=min(a[i]-a[it],a[it])+a[i];
        if(ma<tot) {
            ma=tot;
            ans={a[i],a[it]};
        }
    }
    cout << ans.first << " " << ans.second << endl;
    return 0;
}