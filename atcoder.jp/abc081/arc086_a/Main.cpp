#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll k,n;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll,int> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<ll> p;
    for(auto u:mp) p.push_back(u.second);
    sort(rall(p));
    ll ans=0;
    for(int i=k;i<(int)p.size();i++) ans+=p[i];
    cout << ans << endl;
    return 0;
}