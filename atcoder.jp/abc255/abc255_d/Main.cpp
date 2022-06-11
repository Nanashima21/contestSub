#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,q;
    cin >> n >> q;
    vector<ll> a(n),tot(n+1);
    rep(i,n) cin >> a[i];
    sort(all(a));
    tot[0]=0;
    for(int i=1;i<=n;i++) tot[i]+=tot[i-1]+a[i-1];
    vector<ll> x(q);
    rep(i,q) cin >> x[i];
    rep(i,q) {
        int l=lower_bound(all(a),x[i])-a.begin();
        int r=upper_bound(all(a),x[i])-a.begin();
        ll ltot=tot[l],rtot=tot[n]-tot[r];
        ll ans=0;
        ans+=abs(ltot-l*x[i]);
        ans+=abs(rtot-(n-r)*x[i]);
        cout << ans << endl;
    }
    return 0;
}