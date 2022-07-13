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
    ll tot=a[0],inf=1e18;
    if(tot==0) {
        cout << 0 << endl;
        return 0;
    }
    for(int i=1;i<n;i++) {
        if(a[i]>inf/tot) {
            cout << -1 << endl;
            return 0;
        } else tot*=a[i];
    }
    cout << tot << endl;
    return 0;
}