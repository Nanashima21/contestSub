#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

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

ll modpow(ll n,ll r,ll m) {
    ll num=1;
    n%=m;
    while(r) {
        if(r&1) num=num*n%m;
        n=n*n%m;
        r/=2;
    }
    return num;
}

int main() {
    ll n; string s;
    cin >> n >> s;
    const auto &res=enum_div(n);
    ll ans=0;
    map<ll,ll> mp;
    for(auto u:res) {
        if(n==u) continue;
        vector<bool> flag(u,false);
        rep(i,n) if(s[i]=='.') flag[i%u]=true;
        ll cnt=0,tot=0;
        rep(i,u) if(!flag[i]) cnt++;
        tot=modpow(2,cnt,mod);
        for(auto v:res) {
            if(u==v) break;
            if(u%v==0) tot=(tot-mp[v]+mod)%mod;
        }
        mp[u]=tot;
        ans+=tot;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}