#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll h,w,n;
    cin >> w >> h >> n;
    vector<ll> p(n),q(n);
    rep(i,n) cin >> p[i] >> q[i];
    ll a,b;
    cin >> a;
    vector<ll> la;
    la.push_back(0);
    rep(i,a) {
        ll x;
        cin >> x;
        la.push_back(x);
    }
    la.push_back(w);
    cin >> b;
    vector<ll> lb;
    lb.push_back(0);
    rep(i,b) {
        ll x;
        cin >> x;
        lb.push_back(x);
    }
    lb.push_back(h);
    map<pair<int,int>,ll> mp;  
    rep(i,n) {
        int itl=lower_bound(all(la),p[i])-la.begin()-1;
        int itu=lower_bound(all(lb),q[i])-lb.begin()-1;
        mp[{itl,itu}]++;
    }
    ll ma=0,mi=INF;
    for(auto u:mp) {
        ma=max(ma,u.second);
        mi=min(mi,u.second);
    }
    if((ll)mp.size()!=(a+1)*(b+1)) mi=0;
    cout << mi << " " << ma << endl;
    return 0;
}