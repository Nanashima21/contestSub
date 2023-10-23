#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,q;
    cin >> n >> q;
    vector<set<int>> vs(n);
    ll cnt=n;
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            int u,v;
            cin >> u >> v;
            u--; v--;
            if((int)vs[u].size()==0) cnt--;
            vs[u].insert(v);
            if((int)vs[v].size()==0) cnt--;
            vs[v].insert(u);
        } else {
            int u;
            cin >> u;
            u--;
            if((int)vs[u].size()!=0) cnt++;
            for(auto v:vs[u]) {
                if((int)vs[v].size()==1&&*vs[v].begin()==u) cnt++;
                vs[v].erase(u);
            } 
            set<int> se;
            swap(se,vs[u]);
        }
        cout << cnt << '\n';
    }
    return 0;
}