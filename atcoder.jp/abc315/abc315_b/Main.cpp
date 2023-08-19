#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll m;
    cin >> m;
    vector<ll> d(m);
    rep(i,m) cin >> d[i];
    ll tot=accumulate(all(d),0);
    ll x=(tot+1)/2;
    rep(i,m) {
        if(x>d[i]) x-=d[i];
        else {
            cout << i+1 << " " << x << endl;
            return 0;
        }
    }
    return 0;
}