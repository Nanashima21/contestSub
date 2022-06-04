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
    vector<vector<int>> v(n,vector<int> ());
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> dist(n,-1);
    int q;
    cin >> q;
    while(q--) {
        int x,k;
        cin >> x >> k;
        x--;
        dist[x]=0;
        vector<int> vec;
        queue<int> que;
        que.push(x);
        while(!que.empty()) {
            int u=que.front();
            que.pop();
            vec.push_back(u);
            if(dist[u]==k) continue;
            for(auto nv:v[u]) {
                if(dist[nv]!=-1) continue;
                dist[nv]=dist[u]+1;
                que.push(nv);
            }
        }
        int tot=0;
        for(auto u:vec) {
            tot+=u+1;
            dist[u]=-1;
        }
        cout << tot << endl;
    }
    return 0;
}