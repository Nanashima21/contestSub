#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    vector<pl> p;
    rep(i,n) {
        ll a;
        cin >> a;
        pq.push(a);
    }
    rep(i,m) {
        ll b,c;
        cin >> b >> c;
        p.push_back({c,b});
    }
    sort(rall(p));
    rep(i,m) {
        int cnt=0;
        while(pq.top()<p[i].first) {
            pq.pop(); cnt++;
            pq.push(p[i].first);
            if(cnt==p[i].second) break;
        }
    }
    ll tot=0;
    while(!pq.empty()) {
        tot+=pq.top();
        pq.pop();
    }
    cout << tot << endl;
    return 0;
}