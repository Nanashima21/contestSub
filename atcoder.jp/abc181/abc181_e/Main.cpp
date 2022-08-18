#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> h(n),w(m);
    rep(i,n) cin >> h[i];
    rep(i,m) cin >> w[i];
    w.push_back(INF);
    sort(all(h));
    sort(all(w));
    vector<ll> v;
    for(int i=0;i<n-1;i++) v.push_back(h[i+1]-h[i]);
    ll ans=INF;
    vector<ll> ltot(n),rtot(n);
    if(n!=1) {
        ltot[2]=v[0]; rtot[n-3]=v[n-2];
        for(int i=3;i<n;i++) {
            if(i%2==0) ltot[i]=v[i-2]+ltot[i-2];
            else ltot[i]=ltot[i-1]+h[i+1]-h[i-1];
        }
        for(int i=n-4;i>=0;i--) {
            if(i%2==0) rtot[i]=v[i+1]+rtot[i+2];
            else rtot[i]=rtot[i+1]+h[i+1]-h[i-1];
        }
        if(n==3) ltot[1]=h[2]-h[0];
    }
    rep(i,n) {
        ll cur=ltot[i]+rtot[i];
        ll it=lower_bound(all(w),h[i])-w.begin();
        if(it>0) ans=min(ans,abs(w[it-1]-h[i])+cur);
        ans=min(ans,abs(w[it]-h[i])+cur);
    }
    cout << ans << endl;
    return 0;
}