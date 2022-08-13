#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h1,w1,h2,w2;
    cin >> h1 >> w1;
    vector<vector<ll>> a(h1,vector<ll> (w1));
    rep(i,h1) rep(j,w1) cin >> a[i][j];
    cin >> h2 >> w2;
    vector<vector<ll>> b(h2,vector<ll> (w2));
    rep(i,h2) rep(j,w2) cin >> b[i][j];
    bool flag=false;
    for(ll bit1=0;bit1<(1LL<<h1);bit1++) {
        for(ll bit2=0;bit2<(1LL<<w1);bit2++) {
            ll cnt1=0,cnt2=0;
            rep(i,h1) if(1LL<<i&bit1) cnt1++; 
            rep(i,w1) if(1LL<<i&bit2) cnt2++;
            if(cnt1!=h2) continue;
            if(cnt2!=w2) continue;
            vector<vector<ll>> v(cnt1,vector<ll> (cnt2));
            int ix=0,iy=0;
            rep(i,h1) {
                if(1LL<<i&bit1) {
                    iy=0;
                    rep(j,w1) {
                        if(1LL<<j&bit2) {
                            v[ix][iy]=a[i][j];
                            iy++;
                        }
                    }
                    ix++;
                }
            }
            if(b==v) flag=true;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}