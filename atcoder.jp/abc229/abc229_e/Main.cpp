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
    vector<vector<int>> v(n,vector<int> ()); 
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
    }
    vector<int> ans(1,0);
    int cnt=0;
    UnionFind uf(n);
    for(int i=n-1;i>0;i--) {
        cnt++;
        for(auto u:v[i]) {
            if(!uf.same(u,i)) cnt--;
            uf.unite(u,i); 
        }
        ans.push_back(cnt);
    }
    reverse(all(ans));
    for(auto u:ans) cout << u << endl;
    return 0;
}