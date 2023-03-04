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
    vector<vector<int>> in(n,vector<int> ());
    vector<vector<int>> out(n,vector<int> ());
    vector<vector<bool>> flag(n,vector<bool> (n,false));
    rep(i,n) flag[i][i]=true;
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        in[v].push_back(u);
        out[u].push_back(v);
        flag[u][v]=true;
    }
    queue<int> q;
    rep(i,n) if((int)in.size()!=0) q.push(i);
    ll ans=0;
    while(!q.empty()) {
        int cv=q.front();
        q.pop();
        for(auto nv:out[cv]) {
            int cnt=0;
            for(auto pv:in[cv]) {
                if(flag[pv][nv]) continue;
                in[nv].push_back(pv);
                out[pv].push_back(nv);
                //cout << pv+1  << " " << cv+1 << " " << nv+1 << endl;
                flag[pv][nv]=true;
                cnt++;
                ans++;
            } 
            //if(cnt!=0) q.push(nv);
        }
    }
    cout << ans << endl;
    return 0;
}