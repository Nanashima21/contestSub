#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    set<pl> se1,se2; 
    se2.insert({INF,n});
    vector<pl> v;
    rep(i,m) v.push_back({a[i],i});
    sort(all(v));
    ll tot=0;
    rep(i,m) {
        if(i<k) {
            tot+=v[i].first;
            se1.insert({v[i].first,v[i].second});
        } else se2.insert({v[i].first,v[i].second});
    }
    vector<ll> ans(1,tot);
    for(int i=m;i<n;i++) {
        pl p=*se2.begin();
        if(p.first>a[i]) {
            se1.insert({a[i],i});
            tot+=a[i];
            if(se1.find({a[i-m],i-m})!=se1.end()) {
                tot-=a[i-m];
                se1.erase({a[i-m],i-m});
            } 
            if(se2.find({a[i-m],i-m})!=se2.end()) se2.erase({a[i-m],i-m});
            if((int)se1.size()!=k) {
                pl p2=*se1.rbegin();
                tot-=p2.first;
                se1.erase(p2);
                se2.insert(p2);
            }
        } else {
            if(se1.find({a[i-m],i-m})!=se1.end()) {
                tot-=a[i-m];
                se1.erase({a[i-m],i-m});
            } 
            if(se2.find({a[i-m],i-m})!=se2.end()) se2.erase({a[i-m],i-m});
            se2.insert({a[i],i});
            if((int)se1.size()!=k) {
                tot+=p.first;
                se1.insert(p);
                se2.erase(p);
            }
        }
        ans.push_back(tot);
    }
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}