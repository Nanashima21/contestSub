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

int main() {
    ll n;
    cin >> n;
    vector<ll> v;
    ll ans=0;
    for(ll i=1;i<=n;i++) v.push_back(i*i);
    vector<ll> cnt(n,0);
    set<pair<int,int>> se;
    for(ll i=1;i<=n;i++) {
        const auto &res=enum_div(i);
        for(auto u:res) {
            if(binary_search(all(v),u*i)) {
                ll m=u;
                rep(j,n) {
                    if(m*v[j]<=n) se.insert({n*v[j],i});
                    else break; 
                }
            }
        }
    }
    cout << (ll)se.size() << endl;
    return 0;
}