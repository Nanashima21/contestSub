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
    set<ll> se;
    se.insert(1);
    vector<ll> a(n),b(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
        se.insert(a[i]);
        se.insert(b[i]);
    }
    vector<ll> v;
    map<ll,int> mp;
    int idx=0;
    for(auto u:se) {
        v.push_back(u);
        mp[u]=idx++;
    }
    vector<vector<int>> g(idx,vector<int> ());
    rep(i,n) {
        g[mp[a[i]]].push_back(mp[b[i]]);
        g[mp[b[i]]].push_back(mp[a[i]]);
    }
    queue<int> q;
    q.push(0);
    vector<bool> flag(idx,false);
    flag[0]=true;
    while(!q.empty()) {
        int cv=q.front();
        q.pop();
        for(auto nv:g[cv]) {
            if(flag[nv]) continue;
            flag[nv]=true;
            q.push(nv);
        }
    }
    ll ans=1;
    rep(i,idx) if(flag[i]) ans=v[i];
    cout << ans << endl;
    return 0;
}