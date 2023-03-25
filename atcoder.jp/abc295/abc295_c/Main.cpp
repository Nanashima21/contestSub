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
    vector<ll> a(n);
    map<ll,ll> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans=0;
    for(auto u:mp) ans+=u.second/2;
    cout << ans << endl;
    return 0;
}