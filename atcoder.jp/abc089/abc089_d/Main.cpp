#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w; ll d;
    cin >> h >> w >> d;
    vector<vector<ll>> a(h,vector<ll> (w));
    vector<pair<int,int>> v(h*w+1);
    rep(i,h) rep(j,w) {
        cin >> a[i][j];
        v[a[i][j]]={i,j};
    }
    vector<ll> tot(h*w+1,0);
    for(int i=1;i<=h*w;i++) {
        if(i+d>h*w) break;
        tot[i+d]+=tot[i]+abs(v[i+d].first-v[i].first)+abs(v[i+d].second-v[i].second);
    }
    int q;
    cin >> q;
    while(q--) {
        ll l,r;
        cin >> l >> r;
        cout << tot[r]-tot[l] << "\n";
    }
    return 0;
}