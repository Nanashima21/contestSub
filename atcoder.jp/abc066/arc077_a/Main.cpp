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
    deque<ll> dq;
    rep(i,n) {
        if(i%2==0) dq.push_back(a[i]);
        else dq.push_front(a[i]);
    }
    vector<ll> v;
    while(!dq.empty()) {
        v.push_back(dq.front());
        dq.pop_front();
    }
    if(n%2==1) reverse(all(v));
    rep(i,(int)v.size()) {
        if(i) cout << " ";
        cout << v[i];
    } cout << endl;
    return 0;
}