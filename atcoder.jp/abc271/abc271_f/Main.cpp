#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

pair<int,int> dl[]={{-1,0},{0,-1}};
pair<int,int> dr[]={{1,0},{0,1}};

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> a(n,vector<ll> (n));
    vector<vector<map<ll,ll>>> mp(n,vector<map<ll,ll>> (n));
    rep(i,n) rep(j,n) cin >> a[i][j];
    auto dfs1=[&](auto dfs1,int cy,int cx,ll num) -> void {
        if(n-2==cx+cy) {
            mp[cy][cx][num^a[cy][cx]]++;
        } else {
            if(cy+1<n) dfs1(dfs1,cy+1,cx,num^a[cy][cx]);
            if(cx+1<n) dfs1(dfs1,cy,cx+1,num^a[cy][cx]);
        }
    };
    auto dfs2=[&](auto dfs2,int cy,int cx,ll num) -> void {
        if(n==cx+cy) {
            mp[cy][cx][num^a[cy][cx]]++;
        } else {
            if(cy-1>=0) dfs2(dfs2,cy-1,cx,num^a[cy][cx]);
            if(cx-1>=0) dfs2(dfs2,cy,cx-1,num^a[cy][cx]);
        }
    };
    dfs1(dfs1,0,0,0);
    dfs2(dfs2,n-1,n-1,0);
    ll ans=0;
    rep(i,n) {
        rep(j,2) rep(k,2) {
            int ly=i+dl[j].first,lx=n-i-1+dl[j].second;
            int ry=i+dr[k].first,rx=n-i-1+dr[k].second;
            if(ly<0||ly>=n||lx<0||lx>=n) continue;
            if(ry<0||ry>=n||rx<0||rx>=n) continue;
            for(auto u:mp[ly][lx]) {
                ll num=u.first^a[i][n-i-1];
                if(mp[ry][rx].find(num)==mp[ry][rx].end()) continue;
                else ans+=u.second*mp[ry][rx][num];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
