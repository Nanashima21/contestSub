#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q;
    cin >> n >> q;
    vector<set<int>> vs(n);
    rep(i,n) {
        int c;
        cin >> c;
        vs[i].insert(c);
    }
    while(q--) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        if((int)vs[a].size()>(int)vs[b].size()) swap(vs[a],vs[b]);
        for(auto u:vs[a]) vs[b].insert(u);
        vs[a].clear();
        cout << (int)vs[b].size() << '\n';
    }
    return 0;
}