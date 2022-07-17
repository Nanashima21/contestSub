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
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
    }
    vector<ll> g(n,-1),num(n,-1);
    if(k==1) {
        rep(i,n) num[p[i]]=i+1;
        rep(i,n) cout << num[i] << endl;
        return 0;
    }
    set<ll> se;
    UnionFind uf(n);
    for(int i=0;i<n;i++) {
        if((int)se.size()==0) {
            se.insert(p[i]);
            continue;
        }
        int ma=*se.rbegin();
        if(ma<p[i]) se.insert(p[i]);
        else {
            ll it=*se.lower_bound(p[i]);
            g[p[i]]=it;
            uf.unite(p[i],it);
            se.erase(it);
            if(uf.size(it)!=k) se.insert(p[i]);
            else {
                num[p[i]]=i+1;
                queue<int> q;
                q.push(p[i]);
                while(!q.empty()) {
                    int nv=q.front();
                    q.pop();    
                    if(g[nv]==-1) break;
                    num[g[nv]]=i+1;
                    q.push(g[nv]);
                }
            }
        }
    }
    rep(i,n) cout << num[i] << endl;
    return 0;
}