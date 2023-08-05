#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
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
        v[b].push_back(a);
    }
    set<int> se;
    auto dfs = [&](auto dfs,int cv,vector<bool> flag) -> void {
        if((int)v[cv].size()!=0) {
            rep(i,(int)v[cv].size()) {
                if(!flag[i]) {
                    flag[i]=true;
                    dfs(dfs,v[cv][i],flag);
                }
            }
        } else se.insert(cv);
    };
    rep(i,n) {
        vector<bool> flag(n,false);
        flag[i]=true;
        dfs(dfs,i,flag);
    }
    if((int)se.size()!=1) cout << -1 << endl;
    else cout << *se.begin()+1 << endl;
    return 0;
}