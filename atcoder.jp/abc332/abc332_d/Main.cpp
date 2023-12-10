#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int> (w));
    vector<vector<int>> b(h,vector<int> (w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(i,h) rep(j,w) cin >> b[i][j];
    int ans=100100100;
    map<vector<vector<int>>,int> gm;
    gm[a]=0;
    queue<vector<vector<int>>> que;
    que.push(a);
    while(!que.empty()) {
        vector<vector<int>> g=que.front();
        int d=gm[g];
        que.pop();
        rep(i,h-1) {
            rep(k,w) swap(g[i][k],g[i+1][k]);
            if(gm.find(g)==gm.end()) {
                gm[g]=d+1;
                que.push(g);
            } 
            rep(k,w) swap(g[i][k],g[i+1][k]);
        }
        rep(i,w-1) {
            rep(k,h) swap(g[k][i],g[k][i+1]);
            if(gm.find(g)==gm.end()) {
                gm[g]=d+1;
                que.push(g);
            } 
            rep(k,h) swap(g[k][i],g[k][i+1]);
        }
    }
    if(gm.find(b)==gm.end()) cout << -1 << endl;
    else cout << gm[b] << endl;
    return 0;
}