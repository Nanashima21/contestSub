#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,c;
    cin >> n >> c;
    map<ll,ll> mp;
    rep(i,n) {
        ll a,b,x;
        cin >> a >> b >> x;
        mp[a]+=x;
        mp[b+1]-=x;
    }
    vector<pl> p;
    for(auto u:mp) p.push_back({u.first,u.second});
    ll tot=0;
    for(int i=1;i<(int)p.size();i++) {
        p[i].second+=p[i-1].second;
    }
    for(int i=1;i<(int)p.size();i++) {
        tot+=(p[i].first-p[i-1].first)*min(p[i-1].second,c); 
    }
    cout << tot << endl;
    return 0;
}