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
    vector<ll> t(n),d(n);
    set<ll> se;
    rep(i,n) {
        cin >> t[i] >> d[i];
        se.insert(t[i]);
        se.insert(t[i]+d[i]);
    }
    vector<ll> v;
    for(auto u:se) v.push_back(u);
    int m=(int)v.size();
    map<ll,vector<pl>> mp;
    rep(i,n) {
        ll it1=lower_bound(all(v),t[i])-v.begin();
        ll it2=lower_bound(all(v),t[i]+d[i])-v.begin();
        mp[it1].push_back({i,1}); 
        mp[it2].push_back({i,2});
    }
    ll ans=0,flag=1;
    set<pl> s; 
    rep(i,m) {
        ll sz=(ll)s.size();
        ll x=0;
        if(i!=0) x=max(x,v[i]-v[i-1]-1);
        rep(j,min(x,sz)) {
            s.erase(s.begin());
            ans++;
        }
        for(auto u:mp[i]) {
            if(u.second==1) {
                s.insert({t[u.first]+d[u.first],u.first});
            }
        } 
        if((int)s.size()!=0) {
            s.erase(s.begin());
            ans++;
        }
        for(auto u:mp[i]) {
            if(u.second==2) {
                s.erase({t[u.first]+d[u.first],u.first});
            } 
        } 
        //cout << v[i] << " " << ans << endl;
    } 
    cout << ans << endl;
    return 0;
}