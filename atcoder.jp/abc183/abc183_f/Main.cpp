#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<map<int,ll>> mp;

struct UnionFind {
    vector<ll> v;
    UnionFind(ll n=0): v(n,-1) {}
    int find(ll x) {
        if(v[x]<0) return x;
        return v[x]=find(v[x]);
    }
    bool unite(ll x,ll y) {
        x=find(x);
        y=find(y);
        if(x==y) return false;
        if(v[x]>v[y]) swap(x,y);
        for(auto u:mp[y]) mp[x][u.first]+=u.second;
        v[x]+=v[y];
        v[y]=x;
        return true;
    }
    bool same(ll x,ll y) { return find(x)==find(y); }
    ll size(ll x) { return -v[find(x)]; }
};

int main() {
    ll n,q;
    cin >> n >> q;
    mp.resize(n);
    rep(i,n) {
        int c;
        cin >> c;
        c--;
        mp[i][c]++; 
    }
    UnionFind uf(n);
    while(q--) {
        int t,a,b;
        cin >> t >> a >> b;
        a--; b--;
        if(t==1) uf.unite(a,b); 
        else {
            if(mp[uf.find(a)].find(b)==mp[uf.find(a)].end()) cout << 0 << '\n';
            else cout << mp[uf.find(a)][b] << '\n';
        }
    }
    return 0;
}