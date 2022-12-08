#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n),y(n);
    vector<pl> vx,vy;
    rep(i,n) {
        cin >> x[i] >> y[i];
        vx.push_back({x[i],i});
        vy.push_back({y[i],i});
    }
    sort(all(vx));
    sort(all(vy));
    vector<pair<ll,pair<int,int>>> v;
    v.push_back({vx[n-1].first-vx[0].first,{vx[n-1].second,vx[0].second}});
    v.push_back({vx[n-1].first-vx[1].first,{vx[n-1].second,vx[1].second}});
    v.push_back({vx[n-2].first-vx[0].first,{vx[n-2].second,vx[0].second}});
    v.push_back({vy[n-1].first-vy[0].first,{vy[n-1].second,vy[0].second}});
    v.push_back({vy[n-1].first-vy[1].first,{vy[n-1].second,vy[1].second}});
    v.push_back({vy[n-2].first-vy[0].first,{vy[n-2].second,vy[0].second}});
    sort(rall(v));
    set<pair<int,int>> se;
    se.insert({v[0].second.second,v[0].second.first});
    se.insert(v[0].second);
    int idx=1;
    while(true) {
        if(se.find(v[idx].second)==se.end()) {
            cout << v[idx].first << endl;
            break;
        } 
        idx++;
    }
    return 0;
}