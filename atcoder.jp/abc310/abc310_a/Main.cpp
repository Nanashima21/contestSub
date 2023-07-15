#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,p,q;
    cin >> n >> p >> q;
    ll ans=p;
    rep(i,n) {
        ll d;
        cin >> d;
        ans=min(ans,q+d);
    }
    cout << ans << endl;
    return 0;
}