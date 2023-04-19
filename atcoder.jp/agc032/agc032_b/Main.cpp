#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
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
    int n;
    cin >> n;

    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(n%2==0&&n-i+1==j) continue;
            if(n%2==1&&n-i==j) continue;
            if(n%2==0&&i==1&&j==n) continue;
            ans.push_back({i,j});
        }
    }

    cout << (int)ans.size() << endl;
    rep(i,(int)ans.size()) cout << ans[i].first << " " << ans[i].second << endl;

    /*int m=n*(n-1)/2;
    for(int bit=(1<<m)-1;bit>=0;bit--) {
        UnionFind uf(n);
        vector<vector<int>> g(n,vector<int> ());
        int x=0,y=1;
        rep(i,m) {
            if(bit>>i&1) {
                uf.unite(x,y);
                g[x].push_back(y+1);
                g[y].push_back(x+1);
            }
            if(y==n-1) {
                x++;
                y=x+1;
            } else y++;
        }
        if(uf.size(0)!=n) continue;
        set<int> se;
        rep(i,n) {
            int tot=0;
            for(auto u:g[i]) tot+=u;
            se.insert(tot);
        }
        if((int)se.size()!=1) continue;
        cout << *se.begin() << endl;
        rep(i,n) {
            cout << i+1 << ';';
            for(auto u:g[i]) cout << " " << u;
            cout << endl;
        }
        break;
    }*/
    return 0;
}