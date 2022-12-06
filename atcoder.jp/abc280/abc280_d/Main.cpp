#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<pair<ll,ll>> prime_factorize(ll n) {
    vector<pair<ll,ll>> res;
    for (ll a=2;a*a<=n;++a) {
        if (n%a!=0) continue;
        ll ex=0;
        while(n%a==0) {
            ++ex;
            n/=a;
        }
        res.push_back({a,ex});
    }
    if (n!=1) res.push_back({n,1});
    return res;
    //const auto &res=prime_factorize(n);
}

int main() {
    ll k;
    cin >> k;
    const auto &res=prime_factorize(k);
    ll ans=0;
    for(auto u:res) {
        ll x=u.second;
        ll y=0,n=0;
        while(x>0) {
            n+=u.first;
            y=n;
            while(y%u.first==0) {
                y/=u.first;
                x--;
            }
        }
        ans=max(ans,n);
    }
    cout << ans << endl;
    return 0;
}