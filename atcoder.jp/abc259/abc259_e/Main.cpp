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
    vector<vector<pl>> v(n,vector<pl> ());
    map<ll,vector<ll>> mp;
    rep(i,n) {
        int m;
        cin >> m;
        rep(j,m) {
            ll p,e;
            cin >> p >> e;
            v[i].push_back({p,e});
            mp[p].push_back(e);
        }
    }
    for(auto &u:mp) sort(rall(u.second));
    int cnt=0;
    rep(i,n) {
        bool flag=false;
        rep(j,(int)v[i].size()) {
            ll jp=v[i][j].first,je=v[i][j].second;
            if((int)mp[jp].size()==1) flag=true;
            if(mp[jp][0]!=mp[jp][1]&&mp[jp][0]==je) flag=true; 
        }
        if(flag) cnt++;
    }
    cout << min(cnt+1,n) << endl;
    return 0;
}