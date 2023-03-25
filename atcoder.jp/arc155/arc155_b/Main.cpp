#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll q,a,b;
    cin >> q >> a >> b;
    set<ll> se;
    se.insert(a+b);
    se.insert(a-b);
    while(q--) {
        int t;
        cin >> t >> a >> b;
        if(t==1) {
            se.insert(a+b);
            se.insert(a-b);
        } else {
            ll ans=INF;
            auto it=se.lower_bound(a);
            if(it!=se.end()) {
                if(*it<=b) {
                    cout << 0 << endl;
                    continue;
                }
                ans=min(ans,*it-b);
            }
            if(it!=se.begin()) {
                it--;
                ans=min(ans,a-*it);
            }
            cout << ans << endl;
        }
    }
    return 0;
}