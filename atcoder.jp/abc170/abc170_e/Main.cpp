#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

class SegmentTree {
private:
    ll sz=1,e=INF;
public:
    vector<ll> T;
    SegmentTree(ll n) {
        while(sz<n) sz*=2;
        T=vector<ll> (2*sz,e);
    }
    ll func(ll x,ll y) { return min(x,y); }
    ll at(ll pos) { return T[pos+sz-1]; }
    void update(ll pos,ll num) { //値の更新
        ll now=pos+sz-1;
        T[now]=num;
        while(now>0) {
            now=(now-1)/2;
            T[now]=func(T[2*now+1],T[2*now+2]);
        }
    }
    ll query(ll a,ll b) { return querysub(a,b,0,0,sz); }
    ll querysub(ll a,ll b,ll k,ll l,ll r) { //クエリ処理[a,b)
        if(r<=a||b<=l) return e;
        if(a<=l&&r<=b) return T[k];
        ll lc=querysub(a,b,k*2+1,l,(l+r)/2);
        ll rc=querysub(a,b,k*2+2,(l+r)/2,r);
        return func(lc,rc);
    }
    void show() { rep(i,2*sz-1) cout << i << ' ' << T[i] << endl; }
    //SegmentTree seg(n);
};

int main() {
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n),b(n);
    const ll m=2e5;
    SegmentTree seg(m);
    vector<set<pl>> v(m);
    map<int,int> idx;
    rep(i,n) {
        cin >> a[i] >> b[i];
        b[i]--;
        idx[i]=b[i];
        v[b[i]].insert({-a[i],i});
    }
    rep(i,m) {
        for(auto u:v[i]) {
            seg.update(i,-u.first);
            break;
        } 
    }
    rep(i,q) {
        int c,d;
        cin >> c >> d;
        c--; d--;
        v[idx[c]].erase({-a[c],c});
        for(auto u:v[idx[c]]) {
            seg.update(idx[c],-u.first);
            break;
        }
        if((int)v[idx[c]].size()==0) seg.update(idx[c],INF);
        v[d].insert({-a[c],c});
        for(auto u:v[d]) {
            seg.update(d,-u.first);
            break;
        }
        idx[c]=d;
        cout << seg.query(0,m) << endl;
    }
    return 0;
}