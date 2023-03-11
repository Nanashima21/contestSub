#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int h,w;
vector<vector<ll>> a;
ll ans=0;

int dy[]={1,0};
int dx[]={0,1};
 
void dfs(int y,int x,set<ll> se) {
    if(y==h-1&&x==w-1) {
        ans++;
        return;
    } 
    rep(i,2) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny>=h||nx>=w) continue;
        if(se.find(a[ny][nx])!=se.end()) continue;
        se.insert(a[ny][nx]);
        dfs(ny,nx,se);
        se.erase(a[ny][nx]);
    }
}

int main() {
    cin >> h >> w; 
    a.resize(h,vector<ll> (w));
    rep(i,h) rep(j,w) cin  >> a[i][j];
    set<ll> se;
    se.insert(a[0][0]);
    dfs(0,0,se);
    cout << ans << endl;
    return 0;
}