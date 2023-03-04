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
    map<ll,ll> mp;
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=n;j++) {
            if(i*j>n) break;
            mp[i*j]++;
        }
    }
    ll ans=0;
    for(auto u:mp) {
        ans+=mp[n-u.first]*u.second;
    }
    cout << ans << endl;
    return 0;
}