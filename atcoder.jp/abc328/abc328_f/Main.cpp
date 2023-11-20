#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

template<class Abel> struct PotentialUnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;
    PotentialUnionFind(int n = 1, Abel sum_unity = 0) {
        par.resize(n);
        rank.resize(n, 0);
        diff_weight.resize(n, sum_unity);
        for(int i = 0; i < n; i++) par[i] = i;
    };
    int root(int x) {
        if(par[x] == x) return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
    bool merge(int x, int y, Abel w) {
        w += weight(x) - weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) {
            swap(x, y);
            w = -w;
        }
        if (rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        diff_weight[y] = w;
        return true; 
    }
    bool same(int x, int y) { return root(x) == root(y); }
    Abel weight(int x) { root(x); return diff_weight[x]; }
    Abel diff(int x, int y) { return weight(y) - weight(x); }
    //PotentialUnionFind<ll> uf(n);
};

int main() {
    int n,q;
    cin >> n >> q;
    PotentialUnionFind<ll> uf(n);
    set<int> se;
    rep(i,q) {
        int a,b; ll d;
        cin >> a >> b >> d;
        a--; b--;
        if(uf.same(a,b)&&uf.diff(a,b)==d) se.insert(i+1);
        if(uf.merge(a,b,d)) se.insert(i+1);
    }
    for(auto u:se) cout << u << " ";
    cout << endl;
    return 0;
}