#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll k,n;
    cin >> n >> k;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    rep(i,k) pq.push(p[i]);
    cout << pq.top() << endl;
    for(int i=k;i<n;i++) {
        pq.push(p[i]);
        pq.pop();
        cout << pq.top() << endl;
    }
    return 0;
}