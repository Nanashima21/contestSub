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
    ll x=1;
    while(x*x<m) x++;
    if(x>n) {
        cout << -1 << endl;
        return 0;
    } 
    if(n>=m) cout << m << endl;
    else {
        ll ans=INF;
        for(int i=1;i<=min(n,(ll)1e6);i++) {
            if(m%i==0) {
                if(m/i<=n) ans=min(ans,m);
            } else {
                if(m/i+1<=n) ans=min(ans,(m/i+1)*i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}