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
    vector<pl> p;
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        p.push_back({b,a});
    }
    sort(all(p));
    ll tot=0;
    bool flag=true;
    sort(all(p));
    rep(i,n) {
        tot+=p[i].second;
        if(tot>p[i].first) flag=false; 
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}