#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

ll f(string s) {
    ll ret=0;
    rep(i,(int)s.size()) {
        ret=ret*10+(s[i]-'0');
        ret%=mod;
    }
    return ret%mod;
}

int main() {
    ll n; string sa,sb;
    cin >> n >> sa >> sb;
    rep(i,n) if(sa[i]>sb[i]) swap(sa[i],sb[i]);
    cout << f(sa)*f(sb)%mod << endl;
    return 0;
}