#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll xa,ya,xb,yb,xc,yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ll ans=abs(xb-xc)+abs(yb-yc);
    if(xb!=xc&&yb!=yc) ans+=2;
    vector<ll> dist(4,0); //u,l,r,d;
    if(xa==xb) {
        if(ya<yb) {
            dist[3]=yb-ya-1;
            dist[1]=dist[2]=dist[3]+2;
            dist[0]=dist[1]+2;
        } else {
            dist[0]=ya-yb-1;
            dist[1]=dist[2]=dist[0]+2;
            dist[3]=dist[1]+2;
        } 
    } 
    if(ya==yb) {
        if(xa<xb) {
            dist[1]=xb-xa-1;
            dist[0]=dist[3]=dist[1]+2;
            dist[2]=dist[0]+2;
        } else {
            dist[2]=xa-xb-1;
            dist[0]=dist[3]=dist[2]+2;
            dist[1]=dist[0]+2;
        }
    }
    if(xa<xb&&ya<yb) {
        dist[1]=dist[3]=xb-xa+yb-ya-1;
        dist[0]=dist[2]=dist[1]+2;
    }
    if(xa<xb&&ya>yb) {
        dist[1]=dist[0]=xb-xa+ya-yb-1;
        dist[3]=dist[2]=dist[1]+2;
    }
    if(xa>xb&&ya<yb) {
        dist[2]=dist[3]=xa-xb+yb-ya-1;
        dist[0]=dist[1]=dist[2]+2;
    }
    if(xa>xb&&ya>yb) {
        dist[0]=dist[2]=xa-xb+ya-yb-1;
        dist[1]=dist[3]=dist[2]+2;
    }
    if(xb==xc) {
        if(yb<yc) ans+=dist[3];
        else ans+=dist[0];
    }
    if(yb==yc) {
        if(xb<xc) ans+=dist[1];
        else ans+=dist[2];
    }
    if(xb<xc&&yb<yc) ans+=min(dist[1],dist[3]);
    if(xb<xc&&yb>yc) ans+=min(dist[1],dist[0]);
    if(xb>xc&&yb<yc) ans+=min(dist[2],dist[3]);
    if(xb>xc&&yb>yc) ans+=min(dist[2],dist[0]);
    cout << ans << endl;
    return 0;
}