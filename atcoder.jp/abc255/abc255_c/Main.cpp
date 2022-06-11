#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll x,a,d,n;
    cin >> x >> a >> d >> n;
    ll l=a,r=a+(n-1)*d;
    if(l>r) swap(l,r);
    ll ans=0;
    if(x<=l) ans=l-x;
    else if(r<=x) ans=x-r;
    else {
        ll z=x-a;
        ll y=z/d;
        ans=min(abs(a+y*d-x),abs(a+(y+1)*d-x));
    }
    cout << ans << endl;
    return 0;
}