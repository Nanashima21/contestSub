#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int n;
vector<int> h,cnt;
vector<vector<int>> g;
int ans=-1;

void dfs(int pos,int par,int t) {
    if(t==0) cnt[pos]+=h[pos];
    else ans++;
    for(auto nv:g[pos]) {
        if(par==nv) continue;
        if(t==0) {
            dfs(nv,pos,0);
            cnt[pos]+=cnt[nv];
        } else {
            if(cnt[nv]!=0) {
                dfs(nv,pos,1);
                ans++;
            }
        }
    }
}

int main() {
    int x;
    cin >> n >> x;
    x--;
    h.resize(n);
    rep(i,n) cin >> h[i];
    g.resize(n,vector<int> ());
    rep(i,n-1) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt.resize(n);
    dfs(x,-1,0);
    dfs(x,-1,1);
    cout << ans << endl;
    return 0;
}