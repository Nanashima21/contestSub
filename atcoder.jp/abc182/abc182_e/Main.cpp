#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w,n,m;
    cin >> h >> w >> n >> m;
    vector<int> a(n),b(n),c(m),d(m);
    vector<vector<bool>> g(h,vector<bool> (w,false));
    vector<vector<bool>> flag(h,vector<bool> (w,false));
    vector<vector<bool>> bk(h,vector<bool> (w,false));
    rep(i,n) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        g[a[i]][b[i]]=flag[a[i]][b[i]]=true;
    }
    rep(i,m) {
        cin >> c[i] >> d[i];
        c[i]--; d[i]--;
        bk[c[i]][d[i]]=true;
    } 
    rep(i,h) {
        bool f=false;
        if(flag[i][0]) f=true;
        for(int j=1;j<w;j++) {
            if(flag[i][j]) f=true;
            if(bk[i][j]) f=false;
            g[i][j]=f||g[i][j];
        }
    }
    rep(i,h) {
        bool f=false;
        if(flag[i][w-1]) f=true;
        for(int j=w-2;j>=0;j--) {
            if(flag[i][j]) f=true;
            if(bk[i][j]) f=false;
            g[i][j]=f||g[i][j];
        }
    }
    rep(i,w) {
        bool f=false;
        if(flag[0][i]) f=true;
        for(int j=1;j<h;j++) {
            if(flag[j][i]) f=true;
            if(bk[j][i]) f=false;
            g[j][i]=f||g[j][i];
        }
    }
    rep(i,w) {
        bool f=false;
        if(flag[h-1][i]) f=true;
        for(int j=h-2;j>=0;j--) {
            if(flag[j][i]) f=true;
            if(bk[j][i]) f=false;
            g[j][i]=f||g[j][i];
        }
    }
    int ans=0;
    rep(i,h) rep(j,w) if(g[i][j]) ans++;
    cout << ans << endl;
    return 0;
}