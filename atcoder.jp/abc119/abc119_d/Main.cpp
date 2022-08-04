#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll a,b,q;
    cin >> a >> b >> q;
    vector<ll> tp(a),sr(b);
    rep(i,a) cin >> tp[i];
    tp.push_back(-INF/2); tp.push_back(INF/2);
    rep(i,b) cin >> sr[i];
    sr.push_back(-INF/2); sr.push_back(INF/2);
    sort(all(tp)); sort(all(sr));
    rep(i,q) {
        ll x;
        cin >> x;
        ll it1=lower_bound(all(tp),x)-tp.begin();
        ll it2=lower_bound(all(sr),x)-sr.begin();
        ll dis=INF;
        dis=min(dis,max(tp[it1],sr[it2])-x);
        dis=min(dis,x-min(tp[it1-1],sr[it2-1]));
        dis=min(dis,tp[it1]-sr[it2-1]+min(tp[it1]-x,x-sr[it2-1]));
        dis=min(dis,sr[it2]-tp[it1-1]+min(sr[it2]-x,x-tp[it1-1]));
        cout << dis << endl;
    } 
    return 0;
}