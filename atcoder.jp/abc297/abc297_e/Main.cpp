#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    set<ll> se;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    pq.push(0);
    while(!pq.empty()) {
        ll num=pq.top();
        pq.pop();
        if((int)se.size()>=k&&*se.rbegin()<num) continue;
        rep(i,n) {
            ll tot=num+a[i];
            if(se.find(tot)!=se.end()) continue;
            if((int)se.size()>=k) {
                if(*se.rbegin()>tot) {
                    se.erase(*se.rbegin());
                    se.insert(tot);
                }
            } else se.insert(tot);
            pq.push(tot);
        }
    }
    cout << *se.rbegin() << endl;
    return 0;
}