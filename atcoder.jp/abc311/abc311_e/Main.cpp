#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w,n;
    cin >> h >> w >> n;
    vector<vector<int>> a(h,vector<int> (w));
    vector<vector<ll>> cnt(h,vector<ll> (w,0));
    rep(i,n) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        a[x][y]=1;
    }
    rep(i,h) cnt[i][0]=1-a[i][0];
    rep(i,w) cnt[0][i]=1-a[0][i];
    for(int i=1;i<h;i++) {
        for(int j=1;j<w;j++) {
            if(a[i][j]==1) continue;
            cnt[i][j]=min(min(cnt[i-1][j],cnt[i][j-1]),cnt[i-1][j-1])+1;
        }
    }
    ll ans=0;
    rep(i,h) {
        rep(j,w) {
            ans+=cnt[i][j];
            //cout << " " << cnt[i][j];
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}