#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> g(n,vector<bool> (n));
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u][v]=true;
        g[v][u]=true;
    } 
    int cnt=0;
    rep(i,n) {
        for(int j=i+1;j<n;j++) {
            for(int k=j+1;k<n;k++) {
                if(g[i][j]&&g[i][k]&&g[j][k]) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}