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
    vector<vector<int>> g(n,vector<int> ());
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);       
    }
    vector<int> v;
    rep(i,n) v.push_back(i);
    int ans=0;
    do {
        if(v[0]!=0) break;
        int cv=0,cnt=1;
        while(cnt<n) {
            bool flag=false;
            for(auto nv:g[cv]) {
                if(nv==v[cnt]) {
                    flag=true;
                    cv=nv;
                    cnt++;
                    break;
                } else continue;
            }
            if(!flag) break;
        }
        if(cnt==n) ans++;
    } while(next_permutation(all(v)));
    cout << ans << endl;
    return 0;
}