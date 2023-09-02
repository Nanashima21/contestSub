#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,d,p;
    cin >> n >> d >> p;
    vector<ll> f(n);
    rep(i,n) cin >> f[i];
    sort(all(f));
    for(int i=1;i<n;i++) f[i]+=f[i-1];
    ll ans=INF;
    rep(i,n+1) {
        ll tot=p*i;
        ll idx=n-1-d*i;
        if(idx>=0) tot+=f[idx];
        ans=min(ans,tot);
        if(idx<0) break;
    }
    cout << ans << endl;
    return 0;
}