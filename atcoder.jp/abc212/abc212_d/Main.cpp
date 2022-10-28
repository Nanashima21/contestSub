#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll q;
    cin >> q;
    ll tot=0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    while(q--) {
        int t; ll x;
        cin >> t;
        if(t==1) {
            cin >> x;
            pq.push(x-tot);
        } else if(t==2) {
            cin >> x;
            tot+=x;
        } else {
            cout << pq.top()+tot << '\n';
            pq.pop();
        }
    }
    return 0;
}