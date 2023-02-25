#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<ll> a(n),b(n),c(m),d(m);
    rep(i,n) cin >> a[i]; 
    rep(i,n) cin >> b[i]; 
    rep(i,m) cin >> c[i]; 
    rep(i,m) cin >> d[i]; 
    vector<pair<ll,pair<ll,int>>> v;
    rep(i,n) v.push_back({a[i],{b[i],0}});
    rep(i,m) v.push_back({c[i],{d[i],1}});
    sort(rall(v));
    multiset<ll> ms;
    rep(i,n+m) {
        if(v[i].second.second==1) ms.insert(v[i].second.first);
        else {
            auto it=ms.lower_bound(v[i].second.first);
            if(it==ms.end()) {
                cout << "No" << endl;
                return 0;
            } else ms.erase(it);
        }
    }
    cout << "Yes" << endl;
    return 0;
}