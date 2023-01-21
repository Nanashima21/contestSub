#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> G(n,vector<ll> (n,INF));
    vector<vector<ll>> G2(n,vector<ll> (n,-INF));
    rep(i,n) {
        string s;
        cin >> s;
        rep(j,n) if(s[j]=='Y') {
            G[i][j]=1;
            G2[i][j]=a[j];
        }
    }
    rep(k,n) rep(i,n) rep(j,n) {
        if(G[i][k]+G[k][j]<=G[i][j]) {
            G[i][j]=G[i][k]+G[k][j];
        }  
    }
    rep(k,n) rep(i,n) rep(j,n) {
        if(G[i][k]+G[k][j]==G[i][j]) {
            G2[i][j]=max(G2[i][j],G2[i][k]+G2[k][j]);
        }  
    }
    int q;
    cin >> q;
    while(q--) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        if(G[u][v]==INF||G2[u][v]==-INF) cout << "Impossible" << '\n';
        else cout << G[u][v] << " " << G2[u][v]+a[u] << '\n';
    }
    return 0;
}