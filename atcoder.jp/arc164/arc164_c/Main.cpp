#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    priority_queue<pl,vector<pl>> pq;
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        pq.push({a-b,a});
    }
    ll tot=0;
    while(!pq.empty()) {
        ll x=pq.top().first;
        ll y=pq.top().second;
        pq.pop();
        pq.push({-x,y-x});
        tot+=pq.top().second;
        pq.pop();
    }
    cout << tot << endl;
    return 0;
}