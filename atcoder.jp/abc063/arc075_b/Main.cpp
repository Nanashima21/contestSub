#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    a-=b;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    ll ng=0,ok=1e9;
    while(ok-ng>1) {
        ll mid=(ok+ng)/2;
        ll cnt=0;
        rep(i,n) {
            ll x=h[i]-b*mid;
            if(x<=0) continue;
            cnt+=x/a+(x%a!=0);
        } 
        if(cnt<=mid) ok=mid;
        else ng=mid;
    }
    cout << ok << endl;
    return 0;
}