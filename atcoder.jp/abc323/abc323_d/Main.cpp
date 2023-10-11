#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    map<ll,ll> mp;
    rep(i,n) {
        ll s,c;
        cin >> s >> c;
        mp[s]=c;
    }
    for(auto u:mp) {
        if(u.second<2) continue;
        ll x=u.second;
        mp[u.first*2]+=u.second/2;
        mp[u.first]-=u.second/2*2;
    }
    ll cnt=0;
    for(auto u:mp) cnt+=u.second;
    cout << cnt << endl; 
    return 0;
}