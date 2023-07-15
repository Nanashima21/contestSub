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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<string,ll> mp;
    rep(i,n) {
        string rs=s[i];
        reverse(all(rs));
        if(rs==s[i]) mp[rs]--;
        mp[rs]++; mp[s[i]]++;
    }
    ll ans=0;
    set<string> se;
    for(auto u:mp) {
        string rs=u.first;
        reverse(all(rs));
        if(se.find(rs)!=se.end()) continue;
        if(se.find(u.first)!=se.end()) continue; 
        ans++;
        se.insert(rs);
        se.insert(u.first);
    }
    cout << ans << endl;
    return 0;
}