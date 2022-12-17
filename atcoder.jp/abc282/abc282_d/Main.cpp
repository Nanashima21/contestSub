#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll n;
vector<vector<int>> g;
vector<int> dis;

pl dfs(int pos) {
    ll cnt0=0,cnt1=0;
    if(dis[pos]%2==0) cnt0++;
    else cnt1++;
    for(auto nv:g[pos]) {
        if(dis[nv]!=-1) {
            if((dis[nv]+dis[pos])%2==0) return make_pair(-1,-1);
            continue;
        }
        dis[nv]=dis[pos]+1;
        pl p=dfs(nv);
        if(p.first==-1) return p;
        cnt0+=p.first;
        cnt1+=p.second;
    }
    return make_pair(cnt0,cnt1);
}

int main() {
    ll m;
    cin >> n >> m;
    g.resize(n,vector<int> ());
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans=n*(n-1)/2-m;
    dis.resize(n,-1);
    rep(i,n) {
        if(dis[i]!=-1) continue;
        dis[i]=0;
        pl p=dfs(i);
        if(p.first==-1) {
            cout << 0 << endl;
            return 0;
        } 
        ans-=p.first*(p.first-1)/2;
        ans-=p.second*(p.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}