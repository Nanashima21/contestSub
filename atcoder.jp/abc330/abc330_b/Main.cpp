#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,l,r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> ans(n);
    rep(i,n) {
        if(l<=a[i]&&a[i]<=r) ans[i]=a[i];
        if(l>a[i]) ans[i]=l;
        if(r<a[i]) ans[i]=r;
    }
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}