#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll h,w,cr,cc;
    cin >> h >> w >> cr >> cc;
    ll n;
    cin >> n;
    vector<ll> r(n),c(n);
    set<ll> ser,sec;
    rep(i,n) {
        cin >> r[i] >> c[i];
        ser.insert(r[i]);
        sec.insert(c[i]);
    }
    vector<int> cpr,cpc;
    for(auto u:ser) cpr.push_back(u);
    for(auto u:sec) cpc.push_back(u);
    vector<vector<ll>> nr((int)ser.size(),vector<ll> ());
    vector<vector<ll>> nc((int)sec.size(),vector<ll> ());
    rep(i,n) {
        int itr=lower_bound(all(cpr),r[i])-cpr.begin();
        nr[itr].push_back(c[i]);
        int itc=lower_bound(all(cpc),c[i])-cpc.begin();
        nc[itc].push_back(r[i]);
    }
    rep(i,(int)ser.size()) {
        nr[i].push_back(0);
        nr[i].push_back(w+1);
        sort(all(nr[i]));
    }
    rep(i,(int)sec.size()) {
        nc[i].push_back(0);
        nc[i].push_back(h+1);
        sort(all(nc[i]));
    }
    int q;
    cin >> q;
    while(q--) {
        char d; ll l;
        cin >> d >> l;
        if(d=='L'||d=='R') {
            if(binary_search(all(cpr),cr)) {
                int it=lower_bound(all(cpr),cr)-cpr.begin();
                int it2=lower_bound(all(nr[it]),cc)-nr[it].begin();
                if(d=='L') cc=max(nr[it][it2-1]+1,cc-l);
                else cc=min(nr[it][it2]-1,cc+l);
            } else {
                if(d=='L') cc=max(1LL,cc-l);
                else cc=min(w,cc+l);
            } 
        } else {
            if(binary_search(all(cpc),cc)) {
                int it=lower_bound(all(cpc),cc)-cpc.begin();
                int it2=lower_bound(all(nc[it]),cr)-nc[it].begin();
                if(d=='U') cr=max(nc[it][it2-1]+1,cr-l);
                else cr=min(nc[it][it2]-1,cr+l);
            } else {
                if(d=='U') cr=max(1LL,cr-l);
                else cr=min(h,cr+l);
            }
        }
        cout << cr << " " << cc << "\n";
    }
    return 0;
}