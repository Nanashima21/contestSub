#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,p;
    cin >> n >> m >> p;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(b));
    vector<ll> totb(m+1,0);
    rep(i,m) totb[i+1]+=totb[i]+b[i];
    ll ans=0;
    rep(i,n) {
        auto it=lower_bound(all(b),p-a[i]);
        if(it==b.end()) ans+=totb.back()+a[i]*m;
        else {
            int idx=it-b.begin();
            ans+=totb[idx]+a[i]*idx+p*(m-idx);
        } 
    }
    cout << ans << endl;
    return 0;
}