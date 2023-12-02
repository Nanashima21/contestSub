#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll n;

ll count(vector<vector<ll>> &grid,vector<ll> &cntc,vector<ll> &cntr,ll x,ll y) {
    ll tot=(x/n)*(y/n)*grid[n-1][n-1];
    tot+=cntr[x%n]*(y/n);
    tot+=cntc[y%n]*(x/n);
    tot+=grid[y%n][x%n];
    return tot;
}

int main() {
    ll q;
    cin >> n >> q;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<ll> cntc(n),cntr(n);
    ll totc=0,totr=0;
    rep(i,n) {
        rep(j,n) if(s[i][j]=='B') cntr[j]++;
        rep(j,n) if(s[j][i]=='B') cntc[j]++;   
    }
    rep(i,n-1) {
        cntc[i+1]+=cntc[i];
        cntr[i+1]+=cntr[i];
    }
    vector<vector<ll>> grid(n,vector<ll> (n,0));
    rep(i,n) rep(j,n) if(s[i][j]=='B') grid[i][j]++;
    rep(i,n) for(int j=1;j<n;j++) grid[i][j]+=grid[i][j-1];
    rep(i,n) for(int j=1;j<n;j++) grid[j][i]+=grid[j-1][i];
    // rep(i,(int)cntc.size()) {
    //     if(i) cout << " ";
    //     cout << cntc[i];
    // } cout << endl;
    // rep(i,(int)cntr.size()) {
    //     if(i) cout << " ";
    //     cout << cntr[i];
    // } cout << endl;
    // rep(i,n) {
    //     rep(j,n) {
    //         cout << " " << grid[i][j];
    //     } cout << endl;
    // }
    rep(i,q) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll ans=count(grid,cntc,cntr,d,c);
        if(a>0) ans-=count(grid,cntc,cntr,d,a-1);
        if(b>0) ans-=count(grid,cntc,cntr,b-1,c);
        if(a>0&&b>0) ans+=count(grid,cntc,cntr,b-1,a-1);
        cout << ans << endl;
    }
    return 0;
}