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
    vector<int> p(n-1);
    rep(i,n-1) {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> g(n,vector<int> ());
    for(int i=1;i<n;i++) g[p[i-1]].push_back(i);
    vector<int> sz(n,1),f(n,1);
    const auto dfs = [&](auto &&dfs,int cv) -> void {
        int sum=0;
        vector<int> vec;
        for(auto nv:g[cv]) {
            dfs(dfs,nv);
            sz[cv]+=sz[nv];
            if(sz[nv]%2==1) vec.push_back(-f[nv]);
            else {
                if(f[nv]<0) f[cv]-=-f[nv];
                else sum+=-f[nv];
            } 
        }
        sort(rall(vec));
        vec.push_back(sum);
        rep(i,(int)vec.size()) {
            if(i%2==1) f[cv]+=vec[i];
            else f[cv]-=vec[i];
        }
    };
    dfs(dfs,0);
    cout << (n+f[0])/2 << endl;
    return 0;
}