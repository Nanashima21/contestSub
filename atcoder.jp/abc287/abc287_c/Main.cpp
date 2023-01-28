#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

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
        v[x]+=v[y];
        v[y]=x;
        return true;
    }
    bool same(ll x,ll y) { return find(x)==find(y); }
    ll size(ll x) { return -v[find(x)]; }
    //UnionFind uf(n);
};

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> cnt(n,0);
    UnionFind uf(n);
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        uf.unite(u,v);
        cnt[u]++;
        cnt[v]++;
    } 
    int cnt1=0,cnt2=0;
    rep(i,n) {
        if(cnt[i]==1) cnt1++;
        if(cnt[i]==2) cnt2++;
    }
    cout << ((uf.size(0)==n&&cnt1==2&&cnt2==n-2) ? "Yes" : "No") << endl;
    return 0;
}