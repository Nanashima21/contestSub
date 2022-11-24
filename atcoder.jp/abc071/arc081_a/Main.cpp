#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    map<ll,ll> mp;
    rep(i,n) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    vector<ll> v2,v4;
    for(auto u:mp) {
        if(u.second>=2) v2.push_back(u.first);
        if(u.second>=4) v4.push_back(u.first);
    }
    sort(rall(v2));
    sort(rall(v4));
    ll ans=0;
    if((int)v2.size()>=2) ans=max(ans,v2[0]*v2[1]);
    if((int)v4.size()>=1) ans=max(ans,v4[0]*v4[0]);
    cout << ans << endl;
    return 0;
}