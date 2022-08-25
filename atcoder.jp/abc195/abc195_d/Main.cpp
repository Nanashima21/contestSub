#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    vector<ll> x(m);
    vector<pl> p;
    rep(i,n) {
        ll w,v;
        cin >> w >> v;
        p.push_back({w,v});
    }
    sort(rall(p));
    rep(i,m) cin >> x[i];
    while(q--) {
        int l,r;
        cin >> l >> r;
        l--;
        vector<ll> vec;
        rep(i,m) if(i<l||r<=i) vec.push_back(x[i]);
        sort(all(vec));
        vector<bool> flag(n,false);
        ll tot=0;
        rep(i,(int)vec.size()) {
            ll ma=0; int idx=-1;
            rep(j,n) {
                if(flag[j]) continue;
                if(p[j].first<=vec[i]&&p[j].second>ma) {
                    ma=p[j].second;
                    idx=j;
                }
            }
            if(idx!=-1) flag[idx]=true;
            tot+=ma;
        }
        cout << tot << '\n';
    }
    return 0;
}