#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q;
    cin >> n >> q;
    ll ans=(n-2)*(n-2);
    vector<ll> a(n+1,n),b(n+1,n);
    ll h=n,w=n;
    while(q--) {
        ll t,x;
        cin >> t >> x;
        if(t==1) {
            if(x<w) {
                for(int i=x;i<w;i++) b[i]=h;
                w=x;
            }
            ans-=b[x]-2;
        } else {
            if(x<h) {
                for(int i=x;i<h;i++) a[i]=w;
                h=x;
            }
            ans-=a[x]-2;
        }
    }
    cout << ans << endl;
    return 0;
}