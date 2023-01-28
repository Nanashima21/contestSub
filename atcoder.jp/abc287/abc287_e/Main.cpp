#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=(1LL << 61) - 1;
vector<vector<ll>> h;

ll modpow(ll n,ll r) {
    ll num=1;
    while(r) {
        if(r&1) num=num*n%mod;
        n=n*n%mod;
        r/=2;
    }
    return num;
}

int main() {
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    h.resize(n,vector<ll> ());
    map<ll,ll> mp;
    rep(i,n) {
        h[i].push_back(0);
        mp[0]++;
        for(int j=1;j<=(int)s[i].size();j++) {
            h[i].push_back(((100LL*h[i][j-1])%mod+(s[i][j-1]-'a'+1))%mod);
            mp[h[i][j]]++;
        }
    }
    rep(i,n) {
        int ans=0;
        rep(j,(int)h[i].size()) {
            if(mp[h[i][j]]==1) break;
            ans=max(ans,j);
        }
        cout << ans << '\n';
    }
    return 0;
}