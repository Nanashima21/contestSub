#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<vector<ll>> d(n,vector<ll> (n));
    rep(i,n) rep(j,n) cin >> d[i][j];
    vector<ll> dista(n,INF),distb(n,INF); 
    dista[0]=0; distb[n-1]=0;
    priority_queue<pl,vector<pl>,greater<pl>> pqa,pqb;
    pqa.push({0,0});
    while(!pqa.empty()) {
        ll cd=pqa.top().first;
        int cv=pqa.top().second;
        pqa.pop();
        if(dista[cv]<cd) continue;
        rep(i,n) {
            if(cv==i) continue;
            ll nd=cd+d[cv][i]*a;
            if(nd<dista[i]) {
                dista[i]=nd;
                pqa.push({nd,i});
            }
        }
    }
    pqb.push({0,n-1});
    while(!pqb.empty()) {
        ll cd=pqb.top().first;
        int cv=pqb.top().second;
        pqb.pop();
        if(distb[cv]<cd) continue;
        rep(i,n) {
            if(cv==i) continue;
            ll nd=cd+d[cv][i]*b+c;
            if(nd<distb[i]) {
                distb[i]=nd;
                pqb.push({nd,i});
            }
        }
    }
    ll ans=min(dista[n-1],distb[0]);
    rep(i,n) ans=min(ans,dista[i]+distb[i]);
    cout << ans << endl;
    return 0;
}