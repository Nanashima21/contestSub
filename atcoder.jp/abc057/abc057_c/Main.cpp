#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<ll> enum_div(ll n) {
    vector<ll> ret;
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0) {
            ret.push_back(i);
            if(n/i!=i) ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
    //const auto &res=enum_div(n);
}

ll f(ll x) {
    ll cnt=0;
    while(x!=0) {
        x/=10;
        cnt++;
    }
    return cnt;
}

int main() {
    ll n;
    cin >> n;
    const auto &res=enum_div(n);
    ll ans=INF;
    for(auto u:res) {
        ll p=n/u;
        ans=min(ans,max(f(p),f(u)));
    }
    cout << ans << endl;
    return 0;
}