#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<ll> v(3);
    ll tot=0;
    rep(i,3) {
        cin >> v[i];
        tot+=v[i];
    }
    sort(all(v));
    if(v[0]+v[1]>=v[2]) cout << v[2] << endl;    
    else cout << -1 << endl;
    return 0;
}