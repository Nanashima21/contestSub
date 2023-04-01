#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<vector<int>> g;
vector<bool> flag;

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
    ll n;
    cin >> n;
    vector<ll> a(n);
    g.resize(n,vector<int> ());
    flag.resize(n,false);
    UnionFind uf(n);
    ll cnt=0;
    rep(i,n) {
        cin >> a[i];
        a[i]--;
        if(a[i]==i) {
            cnt++;
            flag[i]=true;
        } else {
            g[i].push_back(a[i]);
            uf.unite(i,a[i]);
        }
    }
    queue<int> q;
    vector<ll> dist(n,INF);
    rep(i,n) {
        if(flag[i]) continue;
        if(flag[uf.find(i)]) continue;
        flag[uf.find(i)]=true;
        dist[i]=0;
        q.push(i);
        while(!q.empty()) {
            int cv=q.front();
            q.pop();
            bool check=false;
            for(auto nv:g[cv]) {
                if(dist[nv]!=INF) {
                    cnt+=dist[cv]-dist[nv]+1;
                    check=true;
                    break;
                }
                dist[nv]=dist[cv]+1;
                q.push(nv);
            }
            if(check) break;
        }
    }
    cout << cnt << endl;
    return 0;
}