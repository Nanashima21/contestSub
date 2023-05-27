#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<vector<int> > g(n,vector<int> ());
    vector<int> deg(n,0);
    rep(i,n-1) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    vector<bool> flag(n,false);
    deque<int> dq;
    rep(i,n) if(deg[i]==1) dq.push_back(i);
    vector<int> ans;
    while(!dq.empty()) {
        int v=dq.front();
        dq.pop_front();
        if(flag[v]) continue;
        flag[v]=true;
        queue<pair<int,int> > q;
        q.push(make_pair(v,0));
        int cnt=1;
        while(!q.empty()) {
            int cv=q.front().first;
            int cd=q.front().second;
            q.pop();
            for(auto nv:g[cv]) {
                if(flag[nv]) continue;
                if(cd==2) dq.push_front(nv);
                else {
                    if(cd==1) cnt++;
                    flag[nv]=true;
                    q.push(make_pair(nv,cd+1));
                }
            }
        }
        if(cnt>1) ans.push_back(cnt);
    }
    sort(all(ans));
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}