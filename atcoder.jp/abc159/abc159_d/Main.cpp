#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll tot=0;
    for(auto u:mp) tot+=u.second*(u.second-1)/2;
    rep(i,n) {
        ll ans=tot;
        ans-=mp[a[i]]*(mp[a[i]]-1)/2;
        ans+=max(0LL,(mp[a[i]]-1)*(mp[a[i]]-2)/2);
        cout << ans << endl;
    }
    return 0;
}