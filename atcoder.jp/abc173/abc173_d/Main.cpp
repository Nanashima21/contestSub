#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(rall(a));
    priority_queue<ll,vector<ll>> pq;
    ll ans=0;
    pq.push(a[0]);
    for(int i=1;i<n;i++) {
        ans+=pq.top();
        pq.pop();
        pq.push(a[i]);
        pq.push(a[i]);
    }
    cout << ans << endl; 
    return 0;
}