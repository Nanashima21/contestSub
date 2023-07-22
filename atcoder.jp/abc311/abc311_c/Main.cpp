#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll n;
vector<vector<int>> g;

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
    cin >> n;
    vector<ll> a(n);
    g.resize(n,vector<int> ());
    UnionFind uf(n);
    vector<bool> flag(n,false);
    vector<int> ans;
    rep(i,n) {
        cin >> a[i];
        a[i]--;
        if(uf.same(i,a[i])) {
            flag[i]=true;
            ans.push_back(i);
            break;
        } else uf.unite(i,a[i]); 
    }
    while(true) {
        if(flag[a[ans.back()]]) break;
        ans.push_back(a[ans.back()]);
        flag[ans.back()]=true;
    }
    cout << (int)ans.size() << endl;
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i]+1;
    } cout << endl;
    return 0;
}